# World-Coordinate System

I have spent some time organising what i now know about coordinate systems and linear algebra.\
\
The world coordinate system starts at origin point (0,0,0) \[x,y,x].

Each axis can be represented by a normalized orientation vector.

Vx = \[1,0,0]

Vy = \[0,1,0]

Vz = \[0,0,1]

These can be combined into a 3x3 matrix representing the orientation of the coordinate system.

This would also be know as an identity matrix.

As...

Vx . Vy = 0

Vx . Vz = 0

Vy . Vz = 0

We know that each axis is orthogonal(perpendicular) to one another.

We also know that since the orientation vectors are normalized, their magnitude is 1.
