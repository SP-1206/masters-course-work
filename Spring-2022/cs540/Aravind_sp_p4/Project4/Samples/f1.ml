( define f()
   (write (- (+ 22 20) ( * 5 (- 2))))
       # 52
)

(define main()
 (seq
   (write (f))
   (f))
)
