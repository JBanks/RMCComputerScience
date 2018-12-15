// Modified by Dr. Yawei Liang, 2016
class Point2D
{
    /* The X and Y coordinates of the point--instance variables */
    private double x;
    private double y;
    private boolean debug;      // A trick to help with debugging

    public Point2D (double px, double py)
    { // Constructor
	x = px;
	y = py;

	debug = false;          // turn off debugging
    }


    public Point2D ()
    { // Default constructor
	this (0.0, 0.0);        // Invokes 2 parameter Point2D constructor
    }


    // Note that a this() invocation must be the BEGINNING of
    // statement body of constructor

    public Point2D (Point2D pt)
    { // Another consructor
	x = pt.getX ();
	y = pt.getY ();

	// a better method would be to replace the above code with
	//    this (pt.getX(), pt.getY());
	// especially since the above code does not initialize the
	// variable debug.  This way we are reusing code that is already
	// working.
    }


    /*
     * Print the debugging string only if the "debug" data member is true
     */
    public void dprint (String s)
    {
	if (debug)
	    System.out.println ("Debug: " + s);
    }


    /*
     * Set the value of debug to true/false to deside if the differences
     * of x and y of the two points should be shown.
     */
    public void setDebug (boolean b)
    {
	debug = b;
    }


    /*
     * Set the value of X for a point
     */
    public void setX (double px)
    {
	dprint ("setX(): Changing value of X from " + x + " to " + px);
	x = px;
    }


    /*
     * Return the value of x for a point
     */
    public double getX ()
    {
	return x;
    }


    /*
     * Set the value of y for a point
     */
    public void setY (double py)
    {
	dprint ("setY(): Changing value of Y from " + y + " to " + py);
	y = py;
    }


    /*
     * Return the value of y for a point
     */
    public double getY ()
    {
	return y;
    }


    /*
     * Set both x an y values for a point
     */
    public void setXY (double px, double py)
    {
	setX (px);
	setY (py);
    }


    /*
     *  Return the distance between current point to pt using 
     *  Pythagorean theorem, i.e., right-angle side^2 + right-angle side^2
     *  = hypotenuse^2
     */
    public double distanceFrom (Point2D pt)
    {
	double dx = Math.abs (x - pt.getX ());
	double dy = Math.abs (y - pt.getY ());

	// check out the use of dprint()
	dprint ("distanceFrom(): deltaX = " + dx);
	dprint ("distanceFrom(): deltaY = " + dy);

	return Math.sqrt ((dx * dx) + (dy * dy));
    }


    /*
     * Return the distance between current to original: (new Point2d())
     */
    public double distanceFromOrigin ()
    {
	return distanceFrom (new Point2D ());
    }


    /*
     * Concatenate output string
     */
    public String toStringForXY ()
    {
	String str = "(" + x + ", " + y;
	return str;
    }


    /*
     * Display the values of x and y instead of the reference of the point
     */
    public String toString ()
    {
	String str = toStringForXY () + ")";
	return str;
    }
}

