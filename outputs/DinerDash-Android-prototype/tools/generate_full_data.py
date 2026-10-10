from pathlib import Path
import json
root=Path(__file__).resolve().parent.parent
app=root
c=json.loads((app/'assets/game-config.json').read_text())
layouts=json.loads((app/'assets/layouts.json').read_text())
colors={'red':0,'blue':1,'green':2,'yellow':3,'purple':4,'none':-1,'grey':-2}
stages=['diner','family','finedining','chezflos','goddess']
names=["Flo's Diner","TGIFlo's","Go with the Flo","Chez Flo's","Goddess Restaurant"]
def q(s):return json.dumps(s,ensure_ascii=True)
def arr(v):return 'new int[] {'+', '.join(map(str,v))+'}'
def table(t):
 ch=t['chairs'];x,y=ch[0]['pos'];return 'new GameEngine.Table(%d, %d, %s)'%(x+1,y,arr([colors[a['color']] for a in ch]))
lines=['package local.dinerdash.prototype;','// Generated from active ext/conf records. Do not substitute the older config.xml.', 'public final class LevelData {','public static final String[] STAGE_NAMES = {'+', '.join(q(s) for s in names)+'};']
lines+=['public static GameEngine.Profile profile(String id) {','switch (id) {']
for id,p in c['customer']['group']['types'].items():
 sd=p['stateData'];states=['waiting','deciding','ready','ordered','eating','check','scoring','leaving','ditching','snack']
 lines+=['case '+q(id)+': return new GameEngine.Profile('+', '.join([q(id),q(p['graphicType']),str(p['baseTip']),str(p['moodTip']),str(p['leavePenalty']),str(p['timeMood']),str(p['colorMood']),str(p.get('heartsRequired',0)),arr([sd[s].get('durationMS',0) for s in states]),arr([sd[s].get('happyMS',0) for s in states]),arr([sd[s].get('madMS',0) for s in states]),arr([sd[s].get('minMS',1000) for s in states])])+');']
lines+=['default: throw new IllegalArgumentException("Unknown recovered profile: " + id);','}','}']
lines+=['public static GameEngine.Level get(int number) {','switch(number) {']
for n in range(1,51):lines+=['case %d: return career%d();'%(n,n)]
lines+=['default: throw new IllegalArgumentException("Career levels are 1-50");','}','}']
def common(d,stage,number,endless=False):
 l=d['layout'];out=['GameEngine.Level l = new GameEngine.Level(%d, %d, %d);'%(number,d.get('minimumTip',400),d.get('bonusGoal',2*d.get('minimumTip',400))), 'l.stage = %d; l.name = STAGE_NAMES[%d]; l.stageId = %s; l.bgState = %s;'%(stage,stage-1,q(stages[stage-1]),q(d.get('bgstate','state_4'))),'l.width = %d; l.height = %d;'%(l['width'],l['height'])]
 for t in l['tables']:out+=['l.tables.add('+table(t)+');']
 bg=layouts[['bg_diner','bg_tiki','bg_seafood','bg_chez','bg_goddess'][stage-1]+'_layout']['children']
 def dest(key,dy=0):
  xy=bg[key]['frames'][0]['loc']['values'];return [max(1,min(18,int((xy[0]-130)//37)+1)),max(1,min(l['height'],int((xy[1]-119)//37)+1))+dy]
 out+=['l.drinkPosition = %s; l.podiumPosition = %s;'%(arr(dest('drinkspot',2)),arr(dest('podium',-1)))]
 for key,field,dy in [('ticketspot','kitchen',1),('busspot','bus',0)]:
  if l[key]:out+=['l.%s = %s;'%(field,arr(dest(key,dy)))]
 if not endless and l['drinkspot']:out+=['l.drinks = l.drinkPosition;']
 foods=[dest('food_'+str(i),1) for i in range(1,6) if 'food_'+str(i) in bg]
 out+=['l.foodPositions = new int[][] {'+', '.join(arr(v) for v in foods)+'};']
 snacks=[dest('snacks_'+str(i),1) for i in range(1,3) if 'snacks_'+str(i) in bg]
 if snacks:out+=['l.snackPositions = new int[][] {'+', '.join(arr(v) for v in snacks)+'};']
 if l.get('bar'):
  b=l['bar'];out+=['l.barX = %d; l.barY = %d; l.barColors = %s;'%(b['chairs'][0]['pos'][0]+1,b['chairs'][0]['pos'][1],arr([colors[x['color']] for x in b['chairs']]))]
 if not endless and d.get('podium'):
  p=d['podium'];out+=['l.podium = l.podiumPosition; l.podiumCharge = %d; l.podiumActive = %d; l.podiumDelay = %d; l.podiumMood = %d;'%(p['chargeMS'],p['activeMS'],p['delayms'],p['moodPoints'])]
 out+=['l.snacks = new String[] {'+', '.join(q(s) for s in d.get('snacks',[]))+'}; l.snackPercent = %d;'%(d.get('snackPercent',0))]
 if not endless:
  for key in ['intro','succeed','fail']:out+=['l.%s = %s;'%(key,q(d.get('text',{}).get(key,'')))]
 return out
for stage in range(1,6):
 for lv in range(1,11):
  n=(stage-1)*10+lv;d=c[f'career_{stage}_{lv}'];lines+=['private static GameEngine.Level career%d() {'%n]+common(d,stage,n)
  time=0
  for g in d['groups']:
   time+=g['queueTimeMS'];lines+=['l.arrivals.add(new GameEngine.Arrival(%dL, %s, %s));'%(time,arr([colors[a['color']] for a in g['customers']]),q(g['type']))]
  lines+=['return l;','}']
lines+=['public static GameEngine.Level endless(int stage, int difficulty) {','switch ((stage-1)*3 + difficulty) {']
for stage in range(1,6):
 for diff in range(1,4):lines+=['case %d: return endless%d_%d();'%((stage-1)*3+diff,stage,diff)]
lines+=['default: throw new IllegalArgumentException("Unknown endless setting");','}','}']
for stage in range(1,6):
 for diff in range(1,4):
  d=c[f'endless_{stage}_{diff}'];lines+=['private static GameEngine.Level endless%d_%d() {'%(stage,diff)]+common(d,stage,0,True)
  lines+=['l.endless = true; l.difficulty = %d; l.stars = %d; l.startMultiplier = %s; l.minMultiplier = %s; l.decrease = %s; l.rampMS = %d;'%(diff,d.get('numStars',c['endless']['stages'][stages[stage-1]].get('numStars',3)),d['startingTimeMultiplier'],d['timeMultiplierMinimum'],d['timeMultiplierDecrease'],d['difficultyIncreaseMS'])]
  for t in d.get('tableUpgrades',[]):lines+=['l.tableUpgrades.add('+table(t)+');']
  for sub in range(1,10):
   s=c[f'endsub_{stage}_{diff}_{sub}'];lines+=['{ GameEngine.Sublevel s = new GameEngine.Sublevel(%d);'%s['goal']]
   for g in s['groups']:lines+=['s.groups.add(new GameEngine.GroupChoice(%s, %d, %d));'%(q(g['type']),g['Frequency'],g['queueTimeMS'])]
   lines+=['s.colors = '+arr([colors[a] for a in s.get('randomColors',['green','red','blue','yellow','purple'])])+'; l.sublevels.add(s); }']
  lines+=['return l;','}']
lines+=['public static GameEngine.Upgrade upgrade(String type, int index) {','switch(type) {']
for t,v in c['powerups'].items():
 lines+=['case '+q(t)+': switch(index) {']
 for n,u in enumerate(v['levels']):
  p=u['properties'];vals=[p.get(k,0) for k in ['chargeMS','activeMS','delayms','moodPoints','drinkRefreshMS','speed','foodReadyMS','patienceMultiplier']]
  lines+=['case %d: return new GameEngine.Upgrade(%s, %s, %s, new double[] {%s});'%(n,q(t),q(u['name']),q(u['description']),', '.join(map(str,vals)))]
 lines+=['default: return null; }']
lines+=['default: return null;','}','}','}']
(app/'src/local/dinerdash/prototype/LevelData.java').write_text('\n'.join(lines)+'\n')
print('Generated 50 career levels, 15 endless maps, 135 sublevels,',len(c['customer']['group']['types']),'profiles and 19 upgrades.')
