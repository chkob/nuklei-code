// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>::GVector (int size)
{
    if (size > 0)
    {
        mSize = size;
        mTuple = new1<Real>(mSize);
        size_t numBytes = mSize*sizeof(Real);
        memset(mTuple, 0, numBytes);
    }
    else
    {
        mSize = 0;
        mTuple = 0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>::GVector (int size, const Real* tuple)
{
    if (size > 0)
    {
        mSize = size;
        mTuple = new1<Real>(mSize);
        size_t numBytes = mSize*sizeof(Real);
        memcpy(mTuple, tuple, numBytes);
    }
    else
    {
        mSize = 0;
        mTuple = 0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>::GVector (const GVector& vec)
{
    mSize = vec.mSize;
    if (mSize > 0)
    {
        mTuple = new1<Real>(mSize);
        size_t numBytes = mSize*sizeof(Real);
        memcpy(mTuple, vec.mTuple, numBytes);
    }
    else
    {
        mTuple = 0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>::~GVector ()
{
    delete1(mTuple);
}
//----------------------------------------------------------------------------
template <typename Real>
void GVector<Real>::SetSize (int size)
{
    delete1(mTuple);
    if (size > 0)
    {
        mSize = size;
        mTuple = new1<Real>(mSize);
        size_t numBytes = mSize*sizeof(Real);
        memset(mTuple, 0, numBytes);
    }
    else
    {
        mSize = 0;
        mTuple = 0;
    }
}
//----------------------------------------------------------------------------
template <typename Real>
inline int GVector<Real>::GetSize () const
{
    return mSize;
}
//----------------------------------------------------------------------------
template <typename Real>
inline GVector<Real>::operator const Real* () const
{
    return mTuple;
}
//----------------------------------------------------------------------------
template <typename Real>
inline GVector<Real>::operator Real* ()
{
    return mTuple;
}
//----------------------------------------------------------------------------
template <typename Real>
inline Real GVector<Real>::operator[] (int i) const
{
    assertion(0 <= i && i < mSize, "Invalid index in operator[]\n");
    return mTuple[i];
}
//----------------------------------------------------------------------------
template <typename Real>
inline Real& GVector<Real>::operator[] (int i)
{
    assertion(0 <= i && i < mSize, "Invalid index in operator[]\n");
    return mTuple[i];
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>& GVector<Real>::operator= (const GVector& vec)
{
    if (vec.mSize > 0)
    {
        if (mSize != vec.mSize)
        {
            delete1(mTuple);
            mSize = vec.mSize;
            mTuple = new1<Real>(mSize);
        }
        size_t numBytes = mSize*sizeof(Real);
        memcpy(mTuple, vec.mTuple, numBytes);
    }
    else
    {
        delete1(mTuple);
        mSize = 0;
        mTuple = 0;
    }
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
bool GVector<Real>::operator== (const GVector& vec) const
{
    return memcmp(mTuple, vec.mTuple, mSize*sizeof(Real)) == 0;
}
//----------------------------------------------------------------------------
template <typename Real>
bool GVector<Real>::operator!= (const GVector& vec) const
{
    return memcmp(mTuple, vec.mTuple, mSize*sizeof(Real)) != 0;
}
//----------------------------------------------------------------------------
template <typename Real>
bool GVector<Real>::operator< (const GVector& vec) const
{
    return memcmp(mTuple, vec.mTuple, mSize*sizeof(Real)) < 0;
}
//----------------------------------------------------------------------------
template <typename Real>
bool GVector<Real>::operator<= (const GVector& vec) const
{
    return memcmp(mTuple, vec.mTuple, mSize*sizeof(Real)) <= 0;
}
//----------------------------------------------------------------------------
template <typename Real>
bool GVector<Real>::operator> (const GVector& vec) const
{
    return memcmp(mTuple, vec.mTuple, mSize*sizeof(Real)) > 0;
}
//----------------------------------------------------------------------------
template <typename Real>
bool GVector<Real>::operator>= (const GVector& vec) const
{
    return memcmp(mTuple, vec.mTuple, mSize*sizeof(Real)) >= 0;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real> GVector<Real>::operator+ (const GVector& vec) const
{
    GVector<Real> result(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        result.mTuple[i] = mTuple[i] + vec.mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real> GVector<Real>::operator- (const GVector& vec) const
{
    GVector<Real> result(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        result.mTuple[i] = mTuple[i] - vec.mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real> GVector<Real>::operator* (Real scalar) const
{
    GVector<Real> result(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        result.mTuple[i] = scalar*mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real> GVector<Real>::operator/ (Real scalar) const
{
    GVector<Real> result(mSize);
    int i;

    if (scalar != (Real)0)
    {
        Real invScalar = ((Real)1)/scalar;
        for (i = 0; i < mSize; ++i)
        {
            result.mTuple[i] = invScalar*mTuple[i];
        }
    }
    else
    {
        for (i = 0; i < mSize; ++i)
        {
            result.mTuple[i] = Math<Real>::MAX_REAL;
        }
    }

    return result;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real> GVector<Real>::operator- () const
{
    GVector<Real> result(mSize);
    for (int i = 0; i < mSize; ++i)
    {
        result.mTuple[i] = -mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>& GVector<Real>::operator+= (const GVector& vec)
{
    for (int i = 0; i < mSize; ++i)
    {
        mTuple[i] += vec.mTuple[i];
    }
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>& GVector<Real>::operator-= (const GVector& vec)
{
    for (int i = 0; i < mSize; ++i)
    {
        mTuple[i] -= vec.mTuple[i];
    }
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>& GVector<Real>::operator*= (Real scalar)
{
    for (int i = 0; i < mSize; ++i)
    {
        mTuple[i] *= scalar;
    }
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
GVector<Real>& GVector<Real>::operator/= (Real scalar)
{
    int i;

    if (scalar != (Real)0)
    {
        Real invScalar = ((Real)1)/scalar;
        for (i = 0; i < mSize; ++i)
        {
            mTuple[i] *= invScalar;
        }
    }
    else
    {
        for (i = 0; i < mSize; ++i)
        {
            mTuple[i] = Math<Real>::MAX_REAL;
        }
    }

    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Real GVector<Real>::Length () const
{
    Real sqrLength = mTuple[0]*mTuple[0];
    for (int i = 1; i < mSize; ++i)
    {
        sqrLength += mTuple[i]*mTuple[i];
    }
    return Math<Real>::Sqrt(sqrLength);
}
//----------------------------------------------------------------------------
template <typename Real>
Real GVector<Real>::SquaredLength () const
{
    Real sqrLength = mTuple[0]*mTuple[0];
    for (int i = 0; i < mSize; ++i)
    {
        sqrLength += mTuple[i]*mTuple[i];
    }
    return sqrLength;
}
//----------------------------------------------------------------------------
template <typename Real>
Real GVector<Real>::Dot (const GVector& vec) const
{
    Real dotProduct = mTuple[0]*vec.mTuple[0];
    for (int i = 0; i < mSize; ++i)
    {
        dotProduct += mTuple[i]*vec.mTuple[i];
    }
    return dotProduct;
}
//----------------------------------------------------------------------------
template <typename Real>
Real GVector<Real>::Normalize (Real epsilon)
{
    Real length = Length();
    int i;

    if (length > epsilon)
    {
        Real invLength = ((Real)1)/length;
        for (i = 0; i < mSize; ++i)
        {
            mTuple[i] *= invLength;
        }
    }
    else
    {
        length = (Real)0;
        for (i = 0; i < mSize; ++i)
        {
            mTuple[i] = (Real)0;
        }
    }

    return length;
}
//----------------------------------------------------------------------------
