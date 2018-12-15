// The "Point3D_Tester" class.
// Modifed by Dr. Yawei Liang, 20160921
public class Point3D_Tester
{
    public static void main (String[] args)
    {
	Point3D pt1 = new Point3D ();
	System.out.println ("pt1 = " + pt1);

	Point3D pt2 = new Point3D (1, 2, 3);
	System.out.println ("pt2 = " + pt2);

	pt1.setDebug (true);        // turn on debugging statements
	// for pt1
	System.out.println ("Distance from " + pt2 + " to " + pt1 +
		" is " + pt2.distanceFrom (pt1));

	System.out.println ("Distance from " + pt1 +
		" to the origin (0, 0, 0) is " + pt1.distanceFromOrigin ());

	System.out.println ("Distance from " + pt2 +
		" to the origin (0, 0, 0) is " + pt2.distanceFromOrigin ());

	pt1.setXYZ (3, 5, 7);
	System.out.println ("pt1 = " + pt1);

	pt2.setXYZ (-3, -5, -7);
	System.out.println ("pt2 = " + pt2);

	System.out.println ("Distance from " + pt1 + " to " + pt2 +
		" is " + pt1.distanceFrom (pt2));

	System.out.println ("Distance from " + pt2 + " to " + pt1 +
		" is " + pt2.distanceFrom (pt1));

	pt1.setDebug (false);       // turning off debugging
	// statements for pt1

	System.out.println ("Distance from " + pt1 +
		" to the origin (0, 0, 0) is " + pt1.distanceFromOrigin ());

	System.out.println ("Distance from " + pt2 +
		" to the origin (0, 0, 0) is " + pt2.distanceFromOrigin ());


    }
} // Point3D_Tester class
