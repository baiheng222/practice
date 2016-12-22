package com.designpatterns.simplefactory;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class CheesePizza extends Pizza
{
    public CheesePizza()
    {
        name = "CheesePizza";
        dough = "Regular Crust";
        sauce = "Marinara Pizza Sauce";
        toppings.add("Fresh Mozzarella");
        toppings.add("Parmesan");

    }
}
