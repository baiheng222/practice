package com.designpatterns.abstractfactory;

import java.util.ArrayList;

/**
 * Created by baiheng222 on 16-12-22.
 */
public abstract class Pizza
{
    String name;
    Dough dough;
    Sauce sauce;
    Veggies veggies[];
    Cheese cheese;
    Pepperoni pepperoni;
    Clams clam;
    //ArrayList topping = new ArrayList();

    abstract void prepare();

    /*
    void prepare()
    {
        System.out.println("Preparing  " + name);
        System.out.println("Tossing dough...");
        System.out.println("Adding sauce...");
        System.out.println("Adding toppings: ");
        for (int i = 0; i < topping.size(); i++)
        {
            System.out.println("  " + topping.get(i));
        }
    }
    */

    void bake()
    {
        System.out.println("Bake for 25 minutes at 350");
    }

    void cut()
    {
        System.out.println("Cutting the pizza into diagonal slices");
    }

    void box()
    {
        System.out.println("Place pizza in official box");
    }

    public String getName()
    {
        return name;
    }

    public void setName(String nm)
    {
         name = nm;
    }

    public String toString()
    {
        StringBuffer result = new StringBuffer();
        result.append("---- " + name + " ----\n");
        if (dough != null) {
            result.append(dough);
            result.append("\n");
        }
        if (sauce != null) {
            result.append(sauce);
            result.append("\n");
        }
        if (cheese != null) {
            result.append(cheese);
            result.append("\n");
        }
        if (veggies != null) {
            for (int i = 0; i < veggies.length; i++) {
                result.append(veggies[i]);
                if (i < veggies.length-1) {
                    result.append(", ");
                }
            }
            result.append("\n");
        }
        if (clam != null) {
            result.append(clam);
            result.append("\n");
        }
        if (pepperoni != null) {
            result.append(pepperoni);
            result.append("\n");
        }
        return result.toString();

    }

}
