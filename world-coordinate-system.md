# World-Coordinate System

I have spent some time organizing what i now know about coordinate systems and linear algebra.\
\
The world coordinate system starts at origin point (0,0,0).

Each axis can be represented by a normalized orientation vector.

$$Vx = \begin{bmatrix}  1 & 0 & 0\end{bmatrix}$$

$$Vy = \begin{bmatrix}  0& 1 & 0\end{bmatrix}$$

$$Vz = \begin{bmatrix}  0 & 0 & 1\end{bmatrix}$$

These can be combined into a 3x3 matrix representing the orientation of the coordinate system.

This would also be know as an identity matrix.

As...

$$Vx\ \cdotp Vy = 0$$

$$Vx\ \cdotp Vz = 0$$

$$Vy\ \cdotp Vz = 0$$



We know that each axis is orthogonal(perpendicular) to one another.

We also know that since the orientation vectors are normalized, their magnitude is 1.
