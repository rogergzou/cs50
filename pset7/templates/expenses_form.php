<form action="expenses.php" method="post">
    <fieldset>
        <div>
            <select id="category_select" name="category_select">
                <?php
                    echo "<option value='blank' selected>select a category</option>";
                    
                    // SQL command returns multidimensional array
                    foreach ($categories as $category)
                    {
                        foreach ($category as $name)
                        {
                            echo "<option value='" . $name . "'>" . $name . "</option>";
                        }
                    }
                ?>
            </select>
        </div>  
        <div id="other">
            <input type="radio" name="other" value="other">other</button>
        </div>
        <div id="category_custom"></div>
        <div id="amount">
            <input name="expense" placeholder="0.00" type="text"/>
        </div>
        <div>
            <button type="submit">Submit Expense</button>
        </div>
    </fieldset>
</form>
