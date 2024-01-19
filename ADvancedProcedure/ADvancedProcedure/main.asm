COMMENT !
Author: Niraj Sangroula
Student ID: 219586770
Lab 1, Part 1
Any and all work in this file is my own.
!

;INCLUDE testproc.inc
INCLUDE Irvine32.inc
.data
aval REAL8 1.0
bval REAL8 2.0
cval REAL8 3.0
r REAL8 ?
; declare variables here
.code
main PROC
	FINIT
	CALL ReadFloat
	FST r
	FLD r
	FMUL
	FLDPI
	FMUL
	CALL WriteFloat


	EXIT
main ENDP
END main

