
(define fact (x) 
   (if (< x 2) x 
   (+ x (fact (- x 1)))
   )
)


(define main()
   (let ((a (read)))
   (seq (write a) (write (fact a)))
   )
)


