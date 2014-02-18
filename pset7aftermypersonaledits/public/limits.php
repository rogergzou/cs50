<?php

    // configuration
    require("../includes/config.php");
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["limit"]) || empty($_POST["category"]))
        {
            apologize("You must provide a limit and a category.");
        }
        
        
        
        $catz = $_POST["category"];
        
        query("ALTER TABLE `limits` ADD `$catz` DECIMAL (65, 4) UNSIGNED NOT NULL DEFAULT 0");
        
        if (query("UPDATE limits SET `$catz` = ? WHERE id = ?", $_POST["limit"], $_SESSION["id"]) === false)
        {
            apologize("Query update failed for some reason."); 
        }
        
        redirect("index.php");
        
    }
    else
    {
        $categories = query("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'limits'");
        $categories_edited = [];
        for ($i = 1, $n = count($categories); $i < $n; $i++)
        {
            $categories_edited[$i - 1] = $categories[$i];
        }
    
        // else render form
        render("limits_form.php", ["title" => "limits", "categories" => $categories_edited]);
    }

?>
