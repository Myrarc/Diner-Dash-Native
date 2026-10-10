# Cookie/customer audit disposition

The final checked findings are in [machine-input.md](machine-input.md) and [customer-events.md](customer-events.md). This replaces the first agent note with corrected state/timing interpretations.

- CookieOven has four FormShelves. Production expiry starts a separate door transition and subtracts the same tick's dt; it does not immediately grant cupcakes. Initial native stock is unresolved.
- A visible cookie-eating fixture uses an ORDER customer. Native's active-menu logic may override the EATING visual for READING customers.
- Timing framestart/frameend is a half-open range. The last frame can use default `.1s`, and native advances at most one frame per draw. Configured time alone is not exact total duration.
- Temporary positive TV/special-event happiness is missing from the Android visual state model. Patience gains and ordinary caps are already represented.
- Native `00560568` converts x87 values to integers; it is not RNG.
- Supplied DisplayCase upgrades contain one shelf. Missing impulse ordering and shelf targeting are confirmed; a four-cake display capacity is not.

The native callback was recovered from the supplied binary using Ghidra in read-only mode. The five host audit probes use Java sources verified against the packaged 0.1.2 compiler/source hashes. They are not Windows runtime or physical-device tests.
