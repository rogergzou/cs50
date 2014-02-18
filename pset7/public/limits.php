<?php

    // configuration
    require("../includes/config.php");
    
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["limit"]))
        {
            apologize_limits("You must provide an expense and a category.");
        }
    
        if ($_POST["category_select"] != "blank")
        {
            $category = $_POST["category_select"];
        }
        else
        {
            apologize_limits("You must provide an expense and a category.");
        }
        
        query("ALTER TABLE `limits` ADD `$category` DECIMAL (65, 4) UNSIGNED NOT NULL DEFAULT 0");
        
        if (query("UPDATE limits SET `$category` = ? WHERE id = ?", $_POST["limit"], $_SESSION["id"]) === false)
        {
            apologize_limits("Query update failed for some reason."); 
        }
        
        redirect("index.php");
        
    }
    else
    {
        $categories = query("SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'limits'");
        $categories_edited = [];
        for ($i = 2, $n = count($categories); $i < $n; $i++)
        {
            $categories_edited[$i - 2] = $categories[$i];
        }
    
        // else render form
        render("limits_form.php", ["title" => "limits", "categories" => $categories_edited]);
    }

?>
