import cppimport.import_hook # isort: skip

import numpy as np
from example import __add, __add_vec, __sum

print(__add(1,2))
print(__add_vec(np.array([1,2]), np.array([3,4])))
print(__sum(np.array([1,2,3])))
