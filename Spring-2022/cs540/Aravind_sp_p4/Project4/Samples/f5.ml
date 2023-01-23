( define f(x y)
  (seq  
    (write (+ x y))
    (let ((x 100) (z  2)) (write (+ x z)))
    (let ((x y) (z  5)) (write (+ x z)))
    (write (+ x y))
       )
)

(define main()
 (seq
   (write (f 10 20))
   (write(f 8 4)
   )
)
)

