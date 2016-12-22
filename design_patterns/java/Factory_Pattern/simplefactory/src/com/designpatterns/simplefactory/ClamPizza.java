package com.designpatterns.simplefactory;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class ClamPizza extends Pizza
{
    public ClamPizza()
    {
        name = "Clam Pizza";
        dough = "Thin crust";
        sauce = "White garlic sauce";
        toppings.add("Clams");
        toppings.add("Grated parmesan cheese");

    }
}
