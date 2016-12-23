package com.designpatterns.abstractfactory;

/**
 * Created by baiheng222 on 16-12-23.
 */
public abstract class PizzaStore
{
    protected abstract Pizza createPizza(String type);

    public Pizza orderPizza(String type)
    {
        Pizza pizza;
        pizza = createPizza(type);
        System.out.println("-----Making a " + pizza.getName() + " ----");
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
        return pizza;
    }
}
