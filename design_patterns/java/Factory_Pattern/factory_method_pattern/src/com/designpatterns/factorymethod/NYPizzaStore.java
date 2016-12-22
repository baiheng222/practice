package com.designpatterns.factorymethod;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class NYPizzaStore extends PizzaStore
{
    public Pizza createPizza(String type)
    {
        if (type.equals("cheese"))
        {
            return new NYStyleCheesePizza();
        }
        else if (type.equals("veggi"))
        {
            return null;
        }
        else
        {
            return null;
        }
    }
}
