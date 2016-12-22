package com.designpatterns.factorymethod;

/**
 * Created by baiheng222 on 16-12-22.
 */
public class ChicagoStyleCheesePizza extends Pizza
{
    public ChicagoStyleCheesePizza()
    {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";

        topping.add("Shredded Mozzarellla Cheese");
    }

    void cut()
    {
        System.out.println("Cutting the pizza into square slices");
    }
}
