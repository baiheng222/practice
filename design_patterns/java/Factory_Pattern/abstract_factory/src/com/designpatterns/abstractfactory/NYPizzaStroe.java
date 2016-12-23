package com.designpatterns.abstractfactory;

/**
 * Created by baiheng222 on 16-12-23.
 */
public class NYPizzaStroe extends PizzaStore
{
    protected Pizza createPizza(String type)
    {
        Pizza pizza = null;
        PizzaIngredientFactory pizzaIngredientFactory = new NYPizzaIngredientFactory();
        if (type.equals("cheese"))
        {
            pizza = new CheesePizza(pizzaIngredientFactory);
            pizza.setName("New York Style Cheese Pizza");
        }
        else if (type.equals("veggie"))
        {
            pizza = new VeggiePizza(pizzaIngredientFactory);
            pizza.setName("New York Style Veggie Pizza");
        }
        else if (type.equals("clam"))
        {
            pizza = new ClamPizza(pizzaIngredientFactory);
            pizza.setName("New York Style Clam Pizza");
        }
        else if (type.equals("pepperoni"))
        {
            pizza = new VeggiePizza(pizzaIngredientFactory);
            pizza.setName("New York Style Pepperoni Pizza");
        }
        return pizza;
    }
}
