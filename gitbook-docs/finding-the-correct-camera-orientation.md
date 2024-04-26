# Finding the Correct Camera Orientation

The orientation of the camera system can be define in the azimuth-elevation spherical coordinate system.\
![](.gitbook/assets/horizontal-coordinate-system.png)

The azimuth represents the rotation around the vertical axis.

The elevation(altitude) represents the rotation above or below the horizontal plane.

These parameters can be assigned as angles in the C programming language:

$$azimuth = \theta$$

$$elevation = \phi$$



We have the matrix:\
$$Vcamera = \begin{bmatrix}  Vxx & Vyx & vzx\\  Vxy & Vyy & Vzy\\ Vxz & Vyz & Vzz \\ \end{bmatrix}$$3D Normalized Orientation Vectors

```c
azimuth = atan2f(Vcamera[Y][Y], Vcamera[X][X]);
elevation = asinf(Vcamera[Z][Z]);
```

arctan is defined as the inverse tangent at a point around a unit circle.\


```
 From ChatGPT:
 
 Keep in mind that these functions return a single angle, and there 
 are multiple angles with the same sine or tangent value. To account 
 for this, some programming languages and mathematical software provide 
 extended functions, such as atan2 (four-quadrant arctangent) and asin (arcsine) 
 that return angles in a wider range while considering the signs of both coordinates.
```

Now we can use the correct two rotation matrices in combination to define the orientation of the camera relative to the world coordinate system.

$$R = Ry(\theta)  \cdot Rx(\phi)$$

$$Ry(\theta) = \begin{bmatrix} cos(\theta) & 0 & sin(\theta)\\ 0 & 1 & 0\\ -sin(\theta) & 0 & cos(\theta)\end{bmatrix}$$

$$Rx(\phi) = \begin{bmatrix} 1& 0 & 0\\ 0 & cos(\phi) & -sin(\phi)\\ 0 & sin(\phi) & cos(\phi)\end{bmatrix}$$



And so our transformation matrix becomes:

So if all vectors are determined to be orthogonal and having a precise approximation of length 1, we should be able to use the values computed from the transformation matrix to define the translated position of camera origin and the placement of vector x, y and z within our world coordinate system.



$$Mfinal = \begin{bmatrix}  Ry(\theta)\ \cdotp Rx(\phi) & \begin{bmatrix} Px \\ Py \\ Pz \\ \end{bmatrix}\\  0 & 1 \\ \end{bmatrix}$$

























