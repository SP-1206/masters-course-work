




(defun sigmoid (u)
  "Sigmoid function applied to the number u"
  (/ 1 (+ 1  (exp  (* -1 u) ))
  ))
  
  
 
  
  
  (defun net-error (output correct-output)
  "Returns (as a scalar value) the error between the output and correct vectors"
(* 0.5 (car (car (multiply (transpose(subtract correct-output output)) (subtract correct-output output)))))
  )
  
  
  
  
  
  ;; a single datum is of the form
;; (--input-column-vector--  -- output-column-vector--)
;;
;; Notice that this is different from the raw data provided in the problems below.
;; You can convert the raw data to this column-vector form using CONVERT-DATA

;; IMPLEMENT THIS FUNCTION

(defun forward-propagate (datum v w)
  "Returns as a vector the output of the OUTPUT units when presented
the datum as input."
 (mapcar #'(lambda (x) (mapcar #'sigmoid x)) (multiply w (mapcar #'(lambda (x) (mapcar #'sigmoid x) ) (multiply v (car datum ))))) 


  )
  
  













;;h = sigmoid[v . i]
;;o = sigmoid[w . h]
;;odelta = (c - o) o (1 - o)
;;hdelta = (h (1 - h) (tr[w] . odelta) )
;;w = w + alpha (odelta . tr[h])
;;v = v + alpha (hdelta . tr[i])


;; IMPLEMENT THIS FUNCTION

(defun back-propagate (datum alpha v w)
  "Back-propagates a datum through the V and W matrices,
returning a list consisting of new, modified V and W matrices."
  ;; Consider using let*
  ;; let* is like let, except that it lets you initialize local
  ;; variables in the context of earlier local variables in the
  ;; same let* statement.
(let* 
(
(h (mapcar #'(lambda (x) (mapcar #'sigmoid x) ) (multiply v (car datum )))) 
(o (mapcar #'(lambda (x) (mapcar #'sigmoid x)) (multiply w h))) 
(odelta (e-multiply (subtract (first(last datum)) o) o (subtract-from-scalar 1 o)))
(hdelta (e-multiply h (subtract-from-scalar 1 h)(multiply (transpose w) odelta)))
(w (add w (scalar-multiply alpha (multiply odelta (transpose h) ))))
(v (add v (scalar-multiply alpha (multiply hdelta (transpose (car datum))))))
)

(list v w)
)

)
  
  
  
  
  



 
 
 
(defun net-build (data num-hidden-units alpha initial-bounds max-iterations modulo &optional print-all-errors)
  "Builds a neural network with num-hidden-units and the appropriate number
of input and output units based on the data.  Each element should be a random
value between -(INITIAL-BOUNDS) and +(INITIAL-BOUNDS).

Then performs the following loop MAX-ITERATIONS times, or until the error condition
is met (see below):

   1. For each data element in a randomized version of the data, perform
      backpropagation.
   2. Every modulo iterations,
          For every data element in the data, perform forward propagation and
          A.  If print-all-errors is true, then print the error for each element
          B.  At any rate, always print the worst error and the mean error
          C.  If the worst error is better (lower) than A-GOOD-MINIMUM-ERROR,
              quit all loops and prepare to exit the function --
              the error condition was met.

The function should return a list of two items: the final V matrix
and the final W matrix of the learned network."


(let ((temp_var '()) (temp_list '()) (temp_min 999) (v (make-random-matrix num-hidden-units (length (first (first data)))  initial-bounds)) (w (make-random-matrix  (length (second (first data))) num-hidden-units initial-bounds))) 
(dotimes (x max-iterations) 
(dolist (z data)
(progn (setf temp_var (back-propagate z alpha v w))  (if print-all-errors
   (print (net-error (last w) (first(last temp_var))) ))  (if(< (net-error (last w) (first(last temp_var))) temp_min)  (setf temp_min (net-error (last w) (first(last temp_var)))) (setf temp_list (list v w)) ))
)) temp_list))




  
  
  
;; For this function, you should pass in the data just like it's defined
;; in the example problems below (that is, not in the "column vector" format
;; used by NET-BUILD.  Of course, if you need to call NET_BUILD from this function
;; you can alway convert this data to column-vector format using CONVERT-DATA within
;; the SIMPLE-GENERALIZATION function.
;;
;; Yes, this is ridiculously inconsistent.  Deal with it.  :-)

;;; IMPLEMENT THIS FUNCTION

(defun simple-generalization (data num-hidden-units alpha initial-bounds max-iterations)
  "Given a set of data, trains a neural network on the first half
of the data, then tests generalization on the second half, returning
the average error among the samples in the second half.  Don't print any errors,
and use a modulo of MAX-ITERATIONS."

(let ((temp_lis '())(temp_vw (net-build (convert-data (subseq data 0 (floor (/ (length data) 2))))  num-hidden-units alpha initial-bounds max-iterations 1000) ) (mod_data (convert-data data))) 

(dolist (x (subseq mod_data 0 (floor (/ (length data) 2))))
(push (net-error (forward-propagate x (first temp_vw) (first (last temp_vw))) (first(last x))) temp_lis)

 )

(average temp_lis)
  )
)


	



;; For this function, you should pass in the data just like it's defined
;; in the example problems below (that is, not in the "column vector" format
;; used by NET-BUILD.  Of course, if you need to call NET_BUILD from this function
;; you can alway convert this data to column-vector format using CONVERT-DATA within
;; the SIMPLE-GENERALIZATION function.
;;
;; Yes, this is ridiculously inconsistent.  Deal with it.  :-)


(defun k-fold-validation (data k num-hidden-units alpha initial-bounds max-iterations)
  "Given a set of data, performs k-fold validation on this data for
the provided value of k, by training the network on (k-1)/k of the data,
then testing generalization on the remaining 1/k of the data.  This is
done k times for different 1/k chunks (and building k different networks).
The average error among all tested samples is returned.  Don't print any errors,
and use a modulo of MAX-ITERATIONS."
(let ((temp_vw (net-build (convert-data (subseq data 0 (floor (/(- k 1) k))))  num-hidden-units alpha initial-bounds max-iterations 1000) ) (mod_data (convert-data data))) 

(dolist (x (subseq mod_data 0 (floor (/ 1 k))))
 (forward-propagate x (first temp_vw) (first (last temp_vw))))
 

  )
  )
  
  (simple-generalization *nand* 3 1.0 5 20000 )




  
  
  


