package Converter;

/** This class will convert between any of the energy units available in the EnergyUnits enum.  It is intended to
*   be included as a member of the Converter package.
*   @author Jeremy Banks (M2104)
*   @version Sept 12, 2018
*/
public class EnergyConverter {

    //This is the workhorse function.  It performs the math for all of the other conversion methods.  To use this
    //method, call Convert with any real number, and provide two units for conversion e.g.:
    // Convert(18.6, EnergyUnits.Calories, EnergyUnits.Joules);
    /** 
    *   @param value The quantity of "currentUnits" that you want to convert.
    *   @param currentUnits The unit that you would like to convert from.  To be selected from the "EnergyUnits" enum.
    *   @param newUnits The unit that you would like to convert to.  To be selected from the "EnergyUnits" enum.
    *   @return The quantity of "newUnits" for a given quantity of "currentUnits".
    */
    public static double Convert(double value, EnergyUnits currentUnits, EnergyUnits newUnits) {
        return value * currentUnits.calories / newUnits.calories;
    }

    /** 
    *   @param Calories The number of calories that will be converted into Joules.
    *   @return The number of Joules for the given number of Calories.
    */
    public static double CaloriesToJoules(double Calories) {
        return Convert(Calories, EnergyUnits.Calories, EnergyUnits.Joules);
    }

    /** 
    *   @param BTUs The number of BTUs that will be converted into ElectronVolts.
    *   @return The number of ElectronVolts for the given number of BTUs.
    */
    public static double BTUToElectronVolts(double BTUs) {
        return Convert(BTUs, EnergyUnits.BTU, EnergyUnits.ElectronVolt);
    }

    /** 
    *   @param wattHours The number of WattHours that will be converted into Tons of Oil Equivalent.
    *   @return The number of Tons of Oil Equivalent for the given number of WattHours.
    */
    public static double WattHourToTOE(double wattHours) {
        return Convert(wattHours, EnergyUnits.WattHour, EnergyUnits.TOE);
    }

    /** 
    *   @param TCE The number of Tons of Carbon Equivalent that will be converted into Therms.
    *   @return The number of Therms for the given number of Tons of Carbon Equivalent.
    */
    public static double TCEToTherm(double TCE) {
        return Convert(TCE, EnergyUnits.TCE, EnergyUnits.Therm);
    }

    /** 
    *   @param ERG The number of Ergs that will be converted into Calories.
    *   @return The number of Calories for the given number of Ergs.
    */
    public static double ErgToCalories(double ERG) {
        return Convert(ERG, EnergyUnits.ERG, EnergyUnits.Calories);
    }

    /** This enum holds all of the available units that you can convert between.  All units are in 
    *	Calories to allow for easy math and addition of food items to the list.
    */
    public enum EnergyUnits {
        Calories(1),
        Joules(0.000239006),
        BTU(0.252164),
        ElectronVolt(3.8293e-23),
        ERG(2.39006e-11),
        WattHour(0.860421),
        Therm(25210.4309031737),
        TOE(1.0E-10),
        TCE(7004684512.4283),
        BigMac(563), //McDonald's
        PizzaSlice(285),
        Bagel(245), //
        Burrito(1175), //Chipotle
        Doughnut(195);
    	
    	/**
    	 * This value is representative of the measurements' relation to calories in order to compare
    	 * all of the different units
    	 */
        public double calories;

        /** 
         *   @param calories the number of calories for one unit of this energy scale.
         */
        EnergyUnits(double calories) {
            this.calories = calories;
        }

    }
}
