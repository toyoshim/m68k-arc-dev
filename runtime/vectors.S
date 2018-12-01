.file "vectors.S"
.section .vectors
.type Vectors, @notype

Vectors:
  dc.l  _stack_top
  dc.l  _start
  dc.l  BusError
  dc.l  AddressError
  dc.l  IllegalInstruction
  dc.l  ZeroDivide
  dc.l  ChkInstruction
  dc.l  TrapvInstruction
  dc.l  PrivilegeViolation
  dc.l  Trace
  dc.l  Line1010Emulation
  dc.l  Line1111Emulation
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  SpuriousInterrupt
  dc.l  Level1Interrupt
  dc.l  Level2Interrupt
  dc.l  Level3Interrupt
  dc.l  Level4Interrupt
  dc.l  Level5Interrupt
  dc.l  Level6Interrupt
  dc.l  Level7Interrupt
  dc.l  Trap0
  dc.l  Trap1
  dc.l  Trap2
  dc.l  Trap3
  dc.l  Trap4
  dc.l  Trap5
  dc.l  Trap6
  dc.l  Trap7
  dc.l  Trap8
  dc.l  Trap9
  dc.l  Trap10
  dc.l  Trap11
  dc.l  Trap12
  dc.l  Trap13
  dc.l  Trap14
  dc.l  Trap15
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0  // reserved
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  dc.l  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
.size Vectors, .-Vectors

.weak BusError
.weak AddressError
.weak IllegalInstruction
.weak ZeroDivide
.weak ChkInstruction
.weak TrapvInstruction
.weak PrivilegeViolation
.weak Trace
.weak Line1010Emulation
.weak Line1111Emulation
.weak SpuriousInterrupt
.weak Level1Interrupt
.weak Level2Interrupt
.weak Level3Interrupt
.weak Level4Interrupt
.weak Level5Interrupt
.weak Level6Interrupt
.weak Level7Interrupt
.weak Trap0
.weak Trap1
.weak Trap2
.weak Trap3
.weak Trap4
.weak Trap5
.weak Trap6
.weak Trap7
.weak Trap8
.weak Trap9
.weak Trap10
.weak Trap11
.weak Trap12
.weak Trap13
.weak Trap14
.weak Trap15

.text
.align 2
.type InfiniteLoop, @function
InfiniteLoop:
BusError:
AddressError:
IllegalInstruction:
ZeroDivide:
ChkInstruction:
TrapvInstruction:
PrivilegeViolation:
Trace:
Line1010Emulation:
Line1111Emulation:
SpuriousInterrupt:
Level1Interrupt:
Level2Interrupt:
Level3Interrupt:
Level4Interrupt:
Level5Interrupt:
Level6Interrupt:
Level7Interrupt:
Trap0:
Trap1:
Trap2:
Trap3:
Trap4:
Trap5:
Trap6:
Trap7:
Trap8:
Trap9:
Trap10:
Trap11:
Trap12:
Trap13:
Trap14:
Trap15:
  bra InfiniteLoop
.size InfiniteLoop, .-InfiniteLoop
