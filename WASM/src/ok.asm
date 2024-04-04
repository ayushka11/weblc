    .ORIG x3000

    ; Load character into R0 (ASCII value of 'A')
    LD R0, ASCII_A

    ; Output character
    OUT
    HALT

ASCII_A .FILL x0041  ; ASCII value of 'A'

    .END