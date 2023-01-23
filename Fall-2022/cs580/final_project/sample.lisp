




(aref board column row)


(defun verticalStreak (game row column streak)
(let ((cc 0))
(do ((c row)) ((> c (height game)))
(if (= (aref (car game) column c) (aref (car game) column row))
(setf cc (+ 1 cc))
)
)
(if (>= cc streak) 1 0)

))


(defun horizontalStreak (game row column streak)
(let ((cc 0))
(do ((c column)) ((> c (width game)))
(if (= (aref (car game) c row) (aref (car game) column row))
(setf cc (+ 1 cc))
)
)
(if (>= cc streak) 1 0)
))

(defun diagonalStreak (game row column streak)
(let ((count 0) (j column))
(do ((c row)) ((> c (height game)))
(if (and (< j (width game))(= (aref (car game) j c) (aref (car game) column row)))
(progn (setf cc (+ 1 cc))) (setf j (+ 1 j)))

)
(if (>= count streak) 1 0)

)
)

(defun checkForStreak (game streak value)
(let ((count 0) )
(dotimes (x (height game))
(dotimes (y (width game))
(if (= (aref (car game) j c) value)
(progn (setf count (+ count (verticalStreak game x y streak)) ) (setf count (+ count (horizontalStreak game x y streak)) ) (setf count (+ count (diagonalStreak game x y streak))))
)
)
)
count
)
)
(load "connectfour")
(compile-file "connectfour.lisp")
(load "connectfour")
(load "aravind-sp")
(compile-file "aravind-sp.lisp")
(load "aravind-sp")
(play-human-computer-game #'aravind-sp:make-computer-move nil)
