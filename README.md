# NotDuino

**Seamlessly use Arduino libraries in non-Arduino projects.**

NotDuino provides core functionality that allows you to utilise Arduino libraries in your own environment.

### Key Features

- Simplifies the integration of Arduino libraries into non-Arduino projects.
- Offers flexibility by excluding a predefined `main()` function.

### Important Note

NotDuino **intentionally** does not implement a `main()` function. This means that if you wish to use it to run an Arduino program on, for example, a PC, you must:

1. Create your own `main()` function.
2. Implement any required drivers for your specific environment.

This design choice ensures maximum adaptability and supports a wide range of use cases.

---

Explore the repository and start integrating Arduino libraries into your custom projects effortlessly!
