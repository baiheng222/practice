package com.designpatterns.abstractfactory;

/**
 * Created by baiheng222 on 16-12-23.
 */
public interface PizzaIngredientFactory
{
    public Dough createDough();
    public Sauce createSauce();
    public Cheese createCheese();
    public Veggies[] createVeggies();
    public Pepperoni createPepperoni();
    public Clams createClam();
}
