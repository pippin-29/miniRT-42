# Camera-Coordinate System

As the assignment provides the parameters to define the camera as&#x20;

World Position P = \[x,y,z]

Vx, Vy, Vz

First: Input parameters must be checked for orthogonality.

Second: Input parameters must be confirmed as normal. (Having the magnitude of 1)

If input parameters are high precision, then a degree of tolerance must be introduced.

Magnitude must be approximately 1 and the dot product of each axis to another must be approximately 0.

The transformation matrix (without a rotation):

$$M = \begin{bmatrix}  1 & 0 & 0 & Px\\  0 & 1 & 0 & Py\\ 0 & 0 & 1 & Pz\\ 0 & 0 & 0 & 1\\ \end{bmatrix}$$Where Px, Py and Pz are the translation coordinates from origin.

This matrix does not contain Vx, Vy and Vz (Normal orientation vectors for the camera)

This matrix can be used to&#x20;
