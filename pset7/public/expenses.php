<?php

    // configuration
    require("../includes/config.php");
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["expense"]))
        {
            apologize_expenses("You must provide an expense and a category.");
        }
    
        if ($_POST["category_select"] != "blank")
        {
            $category = $_POST["category_select"];
        }
        else if (!empty($_POST["category_custom"]))
        {
            $category = $_POST["category_custom"];
            
            query("ALTER TABLE `expenses` ADD `$category` DECIMAL (65, 4) UNSIGNED NOT NULL DEFAULT 0");
            
            query("CREATE TABLE  `finalproject`.`$category` (`id` INT( 10 ) NOT NULL ,`amount` DECIMAL( 65, 4 ) UNSIGNED NOT NULL DEFAULT  '0', `time` DATETIME NOT NULL)");
        }
        else
        {
            apologize_expenses("You must provide an expense and a category.");
        }
        
#        if () === false)
#        {
#            apologize_expenses("wtf table no create for new expense");
#        }
        
        if (query("UPDATE expenses SET `$category` = `$category` + ? WHERE id = ?", $_POST["expense"], $_SESSION["id"]) === false)
        {
            apologize_expenses("Query update failed for some reason."); 

        }
        
        if (query("UPDATE expenses SET total = total + ? WHERE id = ?", $_POST["expense"], $_SESSION["id"]) === false)
        {
            apologize_expenses("Query update failed for some reason.");
        }
        
        if (query("INSERT INTO `finalproject`.`$category` (id, amount, time) VALUES (?, ?, NOW())", $_SESSION["id"], $_POST["expense"])===false)
        {
            apologize_expenses("could not record addition to history of expense sowwi");
        }
        
        if (query("INSERT INTO total (id, amount, time, type) VALUES(?, ?, NOW(), ?)", $_SESSION["id"], $_POST["expense"], $category) === false)
        {
            apologize_expenses("could not update total amount spent");
        }
        
        redirect("index.php");
        
    }
    else
    {
        // else render form
        $categories = query("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'expenses'");
        $categories_edited = [];
        for ($i = 2, $n = count($categories); $i < $n; $i++)
        {
            $categories_edited[$i - 2] = $categories[$i];
        }
    
        render("expenses_form.php", ["title" => "expenses", "categories" => $categories_edited]);
    }

?>
