module.exports = function(){
	var lat1 = Math.random() * 180 - 90;
	var lng1 = Math.random() * 360 - 180;

	var lat2 = Math.random() * 180 - 90;
	var lng2 = Math.random() * 360 - 180;

  var EARTH_RADIUS = 6378.137;//地球半径  
  var PI = 3.1415926535;  
  
  function rad(d){  
    return d * PI / 180.0;  
  }
    
  function round(d){  
    return Math.floor(d + 0.5);  
  }

  var radLat1 = rad(lat1);  
  var radLat2 = rad(lat2);  
  var a = radLat1 - radLat2;  
  var b = rad(lng1) - rad(lng2);  
  var s = 2 * Math.asin(Math.sqrt(Math.pow(Math.sin(a/2),2) + Math.cos(radLat1) * Math.cos(radLat2) * Math.pow(Math.sin(b/2),2)));  
  s = s * EARTH_RADIUS;  
  s = round(s * 10000) / 10000;  
  return s;
}
