dnl 
dnl AC_CXX_BOOL
dnl 
dnl Description
dnl 
dnl If the compiler recognizes bool as a separate built-in type, define HAVE_BOOL.
dnl Note that a typedef is not a separate type since you cannot overload a function
dnl such that it accepts either the basic type or the typedef.
dnl 
dnl Version: 1.2 (last modified: 2000-07-19)
dnl Author: Luc Maisonobe
dnl 
dnl from http://www.gnu.org/software/ac-archive/htmldoc/index.html
dnl 
dnl License:
dnl GNU General Public License
dnl [http://www.gnu.org/software/ac-archive/htmldoc/COPYING.html]
dnl with this special exception
dnl [http://www.gnu.org/software/ac-archive/htmldoc/COPYING-Exception.html]. 
dnl 

AC_DEFUN([AC_CXX_BOOL],
[AC_CACHE_CHECK(whether the compiler recognizes bool as a built-in type,
ac_cv_cxx_bool,
[AC_LANG_SAVE
 AC_LANG_CPLUSPLUS
 AC_TRY_COMPILE([
int f(int  x){return 1;}
int f(char x){return 1;}
int f(bool x){return 1;}
],[bool b = true; return f(b);],
 ac_cv_cxx_bool=yes, ac_cv_cxx_bool=no)
 AC_LANG_RESTORE
])
if test "$ac_cv_cxx_bool" = yes; then
  AC_DEFINE(HAVE_BOOL,,[define if bool is a built-in type])
fi
])
