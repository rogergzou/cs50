<?php

    // configuration
    require("../includes/config.php");
    // if form was submitted
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["expense"]) || empty($_POST["category"]))
        {
            apologize("You must provide an expense and a category.");
        }
        /*else*/ 
        
        $catz = $_POST["category"];
        $expz = $_POST["expense"];
        $idz = $_SESSION["id"];
        if (/*query("INSERT INTO limits (id, limit, category) VALUES(?, ?, ?)", $_SESSION["id"], $_POST["limit"], $_POST["category"])*/
        
        query("ALTER TABLE `expenses` ADD `$catz` DECIMAL (65, 4) UNSIGNED NOT NULL DEFAULT 0") === false )
        
        //query("ALTER TABLE limits ADD '?' DECIMAL( 65, 4 ) UNSIGNED NOT NULL DEFAULT 0" /*ADD UNIQUE ?, $_POST["category"] */, $_POST["category"])===false)
        
        //query ("ALTER TABLE limits ADD tax date") ===false  )
        {
            // probably indicates duplicate but w/e
            // #1060 - Duplicate column name 'food' 
            // apologize("Query failed for some reason.");           
        } else {
            if (query("CREATE TABLE  `finalproject`.`$catz` (`id` INT( 10 ) NOT NULL ,`amount` DECIMAL( 65, 4 ) UNSIGNED NOT NULL DEFAULT  '0',
    `time` DATETIME NOT NULL)")===false)
            {
                apologize("wtf table no create for new expense");
            }
        }
        // query ("ALTER TABLE limits ADD tax date");
        if (query("UPDATE expenses SET `$catz` = `$catz` + ? WHERE id = ?", /*$catz,*/ $expz, $idz/*", $_POST["category"], $_POST["limit"], $_SESSION["id"]*/) === false)
        //if (false)
        {
            apologize("Query update failed for some reason."); 

        }
        if (query("INSERT INTO `finalproject`.`$catz` (id, amount, time) VALUES (?, ?, NOW())", $idz, $expz)===false)
        {
            apologize("could not record addition to history of expense sowwi");
        }
        
        
        
        
        
        /*if (query("CREATE TABLE regularity
(
PersonID int,
LastName varchar(255),
FirstName varchar(255),
Address varchar(255),
City varchar(255)
);")===false) { apologize("hiii~ persons"); }
        */
// create an expense table to track over time the money spent with the category name as table name.T
        /*if (query("CREATE TABLE  `finalproject`.`$catz` (`id` INT( 10 ) NOT NULL ,`amount` DECIMAL( 65, 4 ) UNSIGNED NOT NULL DEFAULT  '0',
`time` DATETIME NOT NULL)")===false)
        {
            apologize("wtf table no create for new expense");
        }*/
        
        




        // assumes query worked and no errors found. also that elif executed query insert
        /*else*/
        
            // $rows = query("SELECT LAST_INSERT_ID() AS id");
            // $id = $rows[0]["id"];
            
            // remember that user's now logged in by storing user's ID in session
            // $_SESSION["id"] = $id;
            // require("login.php");
            // redirect to portfolio
            redirect("index.php");
        
    }
    else
    {
        // else render form
        $categories = query("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'expenses'");
        $categories_edited = [];
        for ($i = 1, $n = count($categories); $i < $n; $i++)
        {
            $categories_edited[$i - 1] = $categories[$i];
        }
    
        render("expenses_form.php", ["title" => "expenses", "categories" => $categories_edited]);
    }

?>
