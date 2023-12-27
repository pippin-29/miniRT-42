# Camera-Coordinate System

As the assignment provides the parameters to define the camera position as&#x20;

$$Pcamera = \begin{bmatrix}  Px & Py & Pz \\ \end{bmatrix}$$

As well as a normalized orientation vector... as defined in the project PDF...

$$Vcamera = \begin{bmatrix}  x & y & z \\ \end{bmatrix}$$

ALTHOUGH...\
I am under the impression, after learning some more about linear algebra and its expression of 3d space, that to correctly define orientation relative to the reference coordinate system there must be three normalized orientation vectors.

$$Vcamera = \begin{bmatrix}  Vxx & Vyx & vzx\\  Vxy & Vyy & Vzy\\ Vxz & Vyz & Vzz \\ \end{bmatrix}$$

This matrix follows a convention that each column defines a 3D normalized vector. If you choose to represent the opposite format (each row is a vector), continue to follow that format.

For simplicity sake, The corresponding axis component of each vector can be 1, whilst the other two are 0. But the possibility to define each vector component in range, provides some room for error.

If a vector is defined as length 1, then it is defined as normalized. using three non-zero components to define a vector allows for precise rotation, although when defining the camera system:

First -  Input parameters must be checked for orthogonality.

Second -  Input parameters must be confirmed as normal. (Having the magnitude of 1)

If input parameters are high precision, then a degree of tolerance must be introduced.

Magnitude must be approximately 1 and the dot product of each axis to another must be approximately 0.

The transformation matrix (without a rotation):

$$M = \begin{bmatrix}  1 & 0 & 0 & Px\\  0 & 1 & 0 & Py\\ 0 & 0 & 1 & Pz\\ 0 & 0 & 0 & 1\\ \end{bmatrix}$$Where Px, Py and Pz are the translation coordinates from origin.

This matrix does not contain Vcamera (Normal orientation vectors for the camera) and will place the camera in at the same orientation as the world coordinate system (i.e Vworld is parallel to Vcamera).



Take note, the assignment states that normalised orientation vectors must be in range 0.0 - 1.0.\
BUT...\
To correctly define the orientation, three vectors must be used within range (-1.0 - 1.0).

```
From ChatGPT:

I see, thanks for the clarification. I misunderstood your question initially. 
Let me clarify:
The reason for limiting the components of a normalized vector to the range [-1, 1] 
is related to the geometric interpretation of vectors and their relationship to 
angles.

When a vector is normalized, it represents a direction in space. The components 
of the vector can be interpreted as the direction cosines of the vector with 
respect to the coordinate axes. These direction cosines are essentially the 
projections of the vector onto each axis, normalized by the length of the vector.

By restricting the components to the range [-1, 1], you ensure that the vector 
is pointing within a hemisphere, and the dot product of two normalized vectors 
can be interpreted as the cosine of the angle between them. The dot product ranges 
from -1 to 1, and when the vectors are normalized, this corresponds to angles 
between 0 and 180 degrees.

If the components were allowed to go beyond the range [-1, 1], the dot product 
might fall outside the valid range for cosine values, and the geometric 
interpretation would break down.
Keeping the components within the [-1, 1] range maintains consistency with 
the interpretation of normalized vectors in terms of angles and projections.

So, in summary, the range [-1, 1] for components of normalized vectors ensures 
geometric consistency and facilitates the interpretation of these vectors in terms 
of angles and projections.
```
