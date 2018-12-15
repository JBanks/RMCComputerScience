package ConverterTest;

import Converter.*;

public class ConverterTestClass {

    private static void printConversion(double newEnergyCount, double oldEnergyCount, String newUnits, String oldUnits) {
        System.out.println("There are " + newEnergyCount
                + " " + newUnits + " in " + oldEnergyCount + " " + oldUnits);
    }

    public static void main(String args[]){
        printConversion(EnergyConverter.BTUToElectronVolts(15),
                15,
                "EV",
                "BTU");
        printConversion(EnergyConverter.CaloriesToJoules(15),
                15,
                "Joules",
                "Calories");
        printConversion(EnergyConverter.ErgToCalories(15),
                15,
                "Calories",
                "ERG");
        printConversion(EnergyConverter.TCEToTherm(15),
                15,
                "Therm",
                "TCE");
        printConversion(EnergyConverter.WattHourToTOE(15),
                15,
                "TOE",
                "wattHour");
        printConversion(EnergyConverter.Convert(4,
                                            EnergyConverter.EnergyUnits.PizzaSlice,
                                            EnergyConverter.EnergyUnits.ElectronVolt),
                        4,
                        "EVs",
                        "PizzaSlices");
    }
}
