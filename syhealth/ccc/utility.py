##############################################################################
# Written by Jared on May 25, 2016.
# All rights reserved.
##############################################################################

import os
from django.utils import timezone

def rebuildPathname(path, username):
    filepath = os.path.dirname(path)
    filename = os.path.basename(path)
    result = filepath + '/' + username + '_' + timezone.now().strftime("%Y%m%d%H%M%S") + '_' + filename
    return result   
