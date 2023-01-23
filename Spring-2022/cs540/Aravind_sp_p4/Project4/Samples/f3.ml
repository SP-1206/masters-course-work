( define f(x y)
  (seq (set x 2)
   (- (+ x 20) ( * y (- 2))))
)

(define main()
 (seq
   (write (f 10 20))
   (write(f 8 4)
   )
)
)
