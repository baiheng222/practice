package com.designpatterns.simplefactory;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class SimplePizzaFactory
{

    public Pizza createPizza(String type)
    {
        Pizza pizza = null;
        if (type.equals("cheese"))
        {
            pizza = new CheesePizza();
        }
        else if (type.equals("pepperoni"))
        {
            pizza = new PepperoniPizza();
        }
        else if (type.equals("veggi"))
        {
            pizza = new VeggiePizza();
        }
        else if (type.equals("clam"))
        {
            pizza = new ClamPizza();
        }

        return pizza;
    }
}
