package com.designpatterns.simplefactory;

import java.util.ArrayList;

/**
 * Created by baiheng222 on 16-12-22.
 */
public abstract class Pizza {
    String name;
    String dough;
    String sauce;
    ArrayList toppings = new ArrayList();

    void prepare()
    {
        System.out.println("Preparing " + name);
        System.out.println("Tossing dough...");
        System.out.println("Adding sauce...");
        System.out.println("adding toppings...");
        for (int i = 0; i< toppings.size();i++)
        {
            System.out.println("  " + toppings.get(i));
        }
    }

    void bake()
    {
        System.out.println("Bake for 25 minutes at 350");
    }

    void cut()
    {
        System.out.println("Cutting the pizza int diagonal slices");
    }

    void box()
    {
        System.out.println("Place pizza in official PizzaStroe box");
    }

    public String getName()
    {
        return name;
    }

}
