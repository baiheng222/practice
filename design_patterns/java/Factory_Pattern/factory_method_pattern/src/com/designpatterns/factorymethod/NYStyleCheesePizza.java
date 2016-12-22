package com.designpatterns.factorymethod;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class NYStyleCheesePizza extends Pizza
{
    public NYStyleCheesePizza()
    {
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        topping.add("Grated Reggiano Cheese");
    }
}
