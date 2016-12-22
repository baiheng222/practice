package com.designpatterns.simplefactory;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class PizzaStore
{
    SimplePizzaFactory factory;

    public PizzaStore(SimplePizzaFactory fac)
    {
        this.factory = fac;
    }

    public Pizza orderPizza(String type)
    {
        Pizza pizza;
        pizza = factory.createPizza(type);

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
}
