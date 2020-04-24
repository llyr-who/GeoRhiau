# GeoRhiau

GeoRhiau is a geometry library. My goal for GeoRhiau is to do "everything geometry", although I will admit that is quite a wide scope. At the moment, this library is concerned with generating 2D triangulations of point clouds. 

Contained within GeoRhiau is some very basic plotting functionality. This will eventually be removed, seriously improved
and moved over the a dedicated repo that will be fetched via CMake. 

## Things to be done

- [x] Implement minimize maximum angle constraint triangulation (Delaunay)
- [ ] Implement minimize maximum edge length constraint triangulation (not the same thing as above).
- [ ] Optimise the above algorithms
