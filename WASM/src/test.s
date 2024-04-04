        .ORIG x3000
        ; Countdown Program
        ; Counts down from 9 to 0, displaying each number on the screen

        LEA R0, MESSAGE ; Load address of MESSAGE into R0
        PUTS            ; Output string to console

        LD R1, NINE     ; Load 9 into R1

COUNT   OUT             ; Output value of R1
        ADD R1, R1, #-1 ; Decrement R1
        BRzp END        ; If R1 == 0, end loop
        BRnzp COUNT     ; Otherwise, continue looping

END     HALT            ; Halt program

MESSAGE .STRINGZ "Countdown: "
NINE    .FILL x0009    ; Value 9
        .END
