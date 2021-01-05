Decorator is a structural pattern that allows adding new behaviors to objects dynamically by placing them inside special wrapper objects.

Intent
Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.
Client-specified embellishment of a core object by recursively wrapping it.
Wrapping a gift, putting it in a box, and wrapping the box.

Problem
You want to add behavior or state to individual objects at run-time. Inheritance is not feasible because it is static and applies to an entire class.

Option 1
Create a new subclass for every topping with a pizza. The class diagram would look like:
Option 2:
Let’s add instance variables to pizza base class to represent whether or not each pizza has a topping. The class diagram would look like:

Sources:
https://refactoring.guru/design-patterns/decorator
https://sourcemaking.com/design_patterns/decorator
