/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkRandomImageSource.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#include "itkRandomImageSource.h"
#include "itkPixelTraits.h"
#include "itkObjectFactory.h"

//------------------------------------------------------------------------
template <class TOutputImage>
itkRandomImageSource<TOutputImage>::Pointer 
itkRandomImageSource<TOutputImage>
::New()
{
  itkRandomImageSource<TOutputImage>* ret = 
    itkObjectFactory< itkRandomImageSource<TOutputImage> >::Create();
  if ( ret )
    {
    return ret;
    }
  return new itkRandomImageSource<TOutputImage>;
}

//----------------------------------------------------------------------------
template <class TOutputImage>
itkRandomImageSource<TOutputImage>
::itkRandomImageSource()
{
  m_Size = new unsigned long [TOutputImage::GetImageDimension()];
  m_Spacing = new float [TOutputImage::GetImageDimension()];
  m_Origin = new float [TOutputImage::GetImageDimension()];
  
}

//----------------------------------------------------------------------------
template <class TOutputImage>
void 
itkRandomImageSource<TOutputImage>
::PrintSelf(std::ostream& os, itkIndent indent)
{
  itkImageSource<TOutputImage>::PrintSelf(os,indent);

}

// Microsoft compiler defines these and screws up the traits

//----------------------------------------------------------------------------
template <class TOutputImage>
void 
itkRandomImageSource<TOutputImage>
::Execute()
{
  typedef typename TOutputImage::ScalarValueType scalarType;

  TOutputImage *image=this->GetOutput(0);
  unsigned int N = image->GetImageDimension();

  scalarType min = itkNumericTraits<scalarType>::min();
  scalarType max = itkNumericTraits<scalarType>::max();
  typename TOutputImage::ScalarIterator scalarIterator = image->ScalarBegin();
  typename TOutputImage::ScalarIterator scalarEnd = image->ScalarEnd();

  itkDebugMacro(<<"Generating a random image of scalars");
  
  for ( scalarIterator=image->ScalarBegin(); 
        scalarIterator != scalarEnd; ++scalarIterator )
    {
    *scalarIterator = (min + max) / 2.0;
    }
  
}
