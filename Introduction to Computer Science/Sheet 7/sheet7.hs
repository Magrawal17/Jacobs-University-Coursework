module BoolExpr (Variable, BoolExpr(..), evaluate,variables,subsets,truthtable) where

import Data.List

type Variable = Char

data BoolExpr
 = T
 | F
 | Var Variable
 | Not BoolExpr
 | And BoolExpr BoolExpr
 | Or BoolExpr BoolExpr
 deriving (Show)

-- evaluates an expression
evaluate :: BoolExpr -> [Variable] -> Bool
evaluate T _ = True
evaluate F _ = False
evaluate (Var v) vs = v `elem` vs
evaluate (Not e) vs = not (evaluate e vs)
evaluate (And e1 e2) vs = evaluate e1 vs && evaluate e2 vs
evaluate (Or e1 e2) vs = evaluate e1 vs || evaluate e2 vs

--7.3.a

variables :: BoolExpr -> [Variable]
variables T = ""
variables F = ""
variables (Var v) = [v]
variables (And e1 e2) = sort $ union (variables e1) (variables e2)
variables (Or e1 e2) = sort $ union (variables e1) (variables e2) 

--7.3.b

subsets :: [Variable] -> [[Variable]]
subsets [] = [[]]
subsets (x:xs) = (subsets xs) ++ (map(x:)(subsets xs))

truthtable ::BoolExpr ->  [([Variable], Bool)]
truthtable e1 = zip (subsets (variables e1)) (map(evaluate e1)(subsets (variables e1)))

