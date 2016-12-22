package com.designpatterns.factorymethod;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class ChicagoPizzaStore extends PizzaStore
{
    public Pizza createPizza(String type)
    {
        if (type.equals("cheese"))
        {
            return new ChicagoStyleCheesePizza();
        }
        else
        {
            return null;
        }
    }
}

