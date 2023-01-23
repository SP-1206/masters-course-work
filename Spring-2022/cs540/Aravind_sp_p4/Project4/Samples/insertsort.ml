(array a 10)
(define setup (size)
   (let ((i 0))
      (while (< i size)
        (seq (set a[i] (read)) (set i (+ i 1)))
      )
   )
)

(define findsmallest(start size)
# return the index of the smallest element from start.. size-1
   (let ((i (+ 1 start))(small start))
      (seq
      (while (< i size)
      (seq (set small (if (< a[i] a[small]) i small))
             (set i (+ i 1))
         )
      )  small
      )
   )
)

(define outputarray(size)
   (let ((i 0))
      (while (< i size)
        (seq (write a[i]) (set i (+ i 1)))
      )
   )
)

(define swaparray (x y)
  ( let ((t 0))
  (seq (set t a[x]) (set a[x] a[y]) (set a[y] t)
    )
  )
)

(define insertsort (size)
    (let ((i 0)(end (- size 1))(x 0))
       (while (< i end)   # size -2
         (seq
          (set x (findsmallest i (+ end 1)))
           (swaparray x i)
          (set i (+ i 1))
         )
       )
    )
)

(define main()
   (seq (setup 10)
        (outputarray 10) (write 9999999) (insertsort 10) (outputarray 10)
   )
)
