package com.company;
//Floats were all changed to doubles before submission.  Updated code was only on the lab computers.
enum Nutrition {
    Calories(1),
    Joules((float)0.000239006),
    BTU((float)0.252164),
    electronVolt((float)3.8293e-23),
    erg((float)2.39006e-11),
    wattHour((float)0.860421),
    therm((float)25210.4309031737),
    toe((float)1.0E-10),
    tce((float)7004684512.4283),
    BigMac(563), //McDonald's
    pizzaSlice(285),
    bagel(245), //
    burrito(1175), //Chipotle
    doughnut(195);
    private float calories;

    Nutrition(float calories) {
        this.calories = calories;
    }

    public static float main(float value, Nutrition currentUnits, Nutrition newUnits) {
        return (value * currentUnits.calories) / newUnits.calories;
    }
}

public class Main {

    public static void main(String[] args) {
        float newFoodStuffs, oldFoodStuffs = 8;
        Nutrition currentUnits = Nutrition.BigMac, newUnits = Nutrition.burrito;
        newFoodStuffs = Nutrition.main(oldFoodStuffs, currentUnits, newUnits);
        System.out.println("There are " + newFoodStuffs
                + " " + newUnits.name() + "s in " + oldFoodStuffs + " " + currentUnits.name() + "s");
    }
}
