package performance_test;

public class Distance {

   private static final double EARTH_RADIUS = 6371.009;// kilometers
   private static final double TO_RADIANS = Math.PI / 180.0;

   /**
    * Calculate the distance between two latitude-longitude points
    * 
    * @param lat1
    *            point 1 latitude
    * @param lng1
    *            point 1 longitude
    * @param lat2
    *            point 2 latitude
    * @param lng2
    *            point 2 longitude
    * @return kilometers
    */
   public static double distance(double lat1, double lng1, double lat2,
         double lng2) {
      // Implements the haversine formula for great-circle distance
      // http://en.wikipedia.org/wiki/Haversine_formula
      // http://en.wikipedia.org/wiki/Great-circle_distance

      double dLat = (lat2 - lat1) * TO_RADIANS;
      double dLng = (lng2 - lng1) * TO_RADIANS;

      double aLat = Math.sin(dLat / 2.0);
      double aLng = Math.sin(dLng / 2.0);
      aLat *= aLat; // squared
      aLng *= aLng; // squared

      double a = aLat + Math.cos(lat1 * TO_RADIANS)
            * Math.cos(lat2 * TO_RADIANS) * aLng;
      double c = 2.0 * Math.atan2(Math.sqrt(a), Math.sqrt(1.0 - a));

      return c * EARTH_RADIUS;
   }
   
   public static double distance() {
      
      double lat1 = Math.random() * 180 - 90;
      double lng1 = Math.random() * 360 - 180;
        
      double lat2 = Math.random() * 180 - 90;
      double lng2 = Math.random() * 360 - 180;
      
      // Implements the haversine formula for great-circle distance
      // http://en.wikipedia.org/wiki/Haversine_formula
      // http://en.wikipedia.org/wiki/Great-circle_distance

      double dLat = (lat2 - lat1) * TO_RADIANS;
      
      double dLng = (lng2 - lng1) * TO_RADIANS;

      double aLat = Math.sin(dLat / 2.0);
      double aLng = Math.sin(dLng / 2.0);
      aLat *= aLat; // squared
      aLng *= aLng; // squared

      double a = aLat + Math.cos(lat1 * TO_RADIANS)
            * Math.cos(lat2 * TO_RADIANS) * aLng;
      double c = 2.0 * Math.atan2(Math.sqrt(a), Math.sqrt(1.0 - a));

      return c * EARTH_RADIUS;
   }

}