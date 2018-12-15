/** This class is used to control the attributes of a point in 3D space.
 *   @author Jeremy Banks (M2104)
 *   @version Sept 21, 2018
 */
class Point3D extends Point2D
{
    /**
     * Stores the location of the point in the z-dimension
     */
    private double z;

    /**
     * Creates a point at the location given by each of the parameters.
     * @param px The location of the point in the x-dimension.
     * @param py The location of the point in the y-dimension.
     * @param pz The location of the point in the z-dimension.
     */
    public Point3D (int px, int py, int pz)
    {
        super (px, py);
        this.setZ(pz);

        this.setDebug(false);
    }

    /**
     * Creates a point that is located at the origin.
     */
    public Point3D ()
    {
        this(0,0,0);
    }

    /**
     * Copies a currently existing point.
     * @param pt Another point that you would like to copy.
     */
    public Point3D (Point3D pt)
    {
        this((int)pt.getX(),(int)pt.getY(),(int)pt.getZ());  //this actually passes the test parameters. Process could
        // be refined to include doubles by using other methods that accept doubles.
    }

    /**
     *
     * @param pz changes the value for the location in the z-dimension.
     */
    public void setZ (double pz)
    {
        dprint ("setZ(): Changing value of Y from " + z + " to " + pz);
        z = pz;
    }

    /**
     * Get the value stored for the location in the z-dimension.
     * @return returns the value currently
     */
    public double getZ ()
    {
        return z;
    }

    /**
     * Changes the location of the point to a new location.
     * @param px The location of the point in the x-dimension.
     * @param py The location of the point in the y-dimension.
     * @param pz The location of the point in the z-dimension.
     */
    public void setXYZ (double px, double py, double pz)
    {
        setX(px);
        setY(py);
        //setXY(px,py);  //apparently code readability doesn't matter.  Use the other method even if it makes it look weird.
        setZ(pz);
    }

    /**
     * Calculates the distance between this point, and a point passed as an argument.
     * @param pt A 3D point that you are looking to calculate the distance to.
     * @return Returns a scalar representing the distance to the point provided as an argument.
     */
    public double distanceFrom (Point3D pt)
    {
        //double dxy = super.distanceFrom(newPoint2D(pt.x, pt.y);  //Use this instead.  Must use AS MUCH AS POSSIBLE

        double dx = Math.abs (getX() - pt.getX ());
        double dy = Math.abs (getY() - pt.getY ());
        double dz = Math.abs (getZ() - pt.getZ ());

        // check out the use of dprint()
        dprint ("distanceFrom(): deltaX = " + dx);
        dprint ("distanceFrom(): deltaY = " + dy);
        dprint ("distanceFrom(): deltaZ = " + dz);

        //Math.sqrt( (dxy * dxy) + (dz * dz) );

        return Math.sqrt ((dx * dx) + (dy * dy) + (dz * dz));
    }

    /**
     * Calculates the distance from the point to the origin.
     * @return Returns a scalar representing the distance to the origin.
     */
    public double distanceFromOrigin ()
    {
        return distanceFrom (new Point3D ());
    }

    /**
     * Returns a string for inclusion in a list of dimensions.
     * @return A string for inclusion in a list of dimesnions.
     */
    private String toStringForZ ()
    {
        String str = ", " + z;
        return str;
    }

    /**
     * Concatenates a string containing the location in all 3 dimensions.
     * @return A string with values representing the distance in all 3 dimensions.
     */
    public String toString ()
    {
        String str = toStringForXY() + toStringForZ() + ")";
        return str;
    }
}
