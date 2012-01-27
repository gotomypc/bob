#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
# Laurent El Shafey <laurent.el-shafey@idiap.ch>

"""Tests bob square root of a matrix computation.
"""

import os, sys
import unittest
import bob
import numpy

class SqrtmTest(unittest.TestCase):
  """Tests the square root of a matrix computation based on Lapack"""
 
  def test01_sqrtSymReal(self):
    # This test demonstrates how to compute the square root of a reall
    # symmetric positive-definite matrix

    N = 4
    # Matrix to decompose
    A = numpy.array([1, -1, 0, 0,  -1, 2, -1, 0, 0, -1, 2, -1, 0, 0, -1, 1],
    'float64').reshape(N,N)

    # Matrix for storing the result
    C = numpy.ndarray((4,4), 'float64')

    # Computes the square root (using the two different python methods)
    bob.math.sqrtSymReal(A,C)
    B=bob.math.sqrtSymReal(A)

    import scipy.linalg
    ref_Sci = scipy.linalg.sqrtm(A)

    # Compare square root to matlab reference
    ref=numpy.array(
      [ 0.81549316, -0.54489511, -0.16221167, -0.10838638,
       -0.54489510,  1.19817659, -0.49106981, -0.16221167,
       -0.16221167, -0.49106981,  1.19817659, -0.54489511,
       -0.10838638, -0.16221167, -0.54489511,  0.81549316]).reshape(4,4)
    self.assertEqual( (abs(B-ref) < 1e-4).all(), True )
    self.assertEqual( (abs(C-ref) < 1e-4).all(), True )
    self.assertEqual( (abs(B-ref_Sci) < 1e-4).all(), True )
    self.assertEqual( (abs(C-ref_Sci) < 1e-4).all(), True )
   
if __name__ == '__main__':
  sys.argv.append('-v')
  if os.environ.has_key('BOB_PROFILE') and \
      os.environ['BOB_PROFILE'] and \
      hasattr(bob.core, 'ProfilerStart'):
    bob.core.ProfilerStart(os.environ['BOB_PROFILE'])
  os.chdir(os.path.realpath(os.path.dirname(sys.argv[0])))
  unittest.main()
  if os.environ.has_key('BOB_PROFILE') and \
      os.environ['BOB_PROFILE'] and \
      hasattr(bob.core, 'ProfilerStop'):
    bob.core.ProfilerStop()
