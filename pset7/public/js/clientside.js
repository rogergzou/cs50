$(window).load(function() {

    $("#other").change(function() {
        category();
    });
    
    $("#category_select").change(function() {
        change();
    });
    
    $("#view_total").click(function() {
        view_total();
    });
    
    $("#view_comparison").click(function() {
        view_comparison();
    });
});

function category()
{
    var html = "<input name='category_custom' placeholder='Category' type='text'/>";
    
    $("#category_custom").html(html);
    
    $("option:selected").prop("selected", false);
}

function change()
{
    var html = "<input type='radio' name='other' value='other'>other</input>";
    
    $("#other").html(html);
    $("#category_custom").html("");
}

function view_comparison()
{
    var html = "<canvas id='myChart' width='400' height='400'></canvas>"
    
    $("#chart_comparison").html(html);
    
    var ctx = $("#myChart").get(0).getContext("2d");
    
    var data = {
            labels : (function() {
                return categories;
            })(),
            datasets : [
                    {
                        data : (function() {
                            return spending;
                        })(),
                    }
            ]
    };
    
    var options = {
            scaleLineWidth : 1
    };
    
    new Chart(ctx).Bar(data, options);
}

function view_total()
{
    var html = "<canvas id='myChart' width='400' height='400'></canvas>";
    
    $("#chart_total").html(html);
    
    var ctx = $("#myChart").get(0).getContext("2d");
    
    var data = {
            labels : (function() {
                return expenses_monthly;
            })(),
            datasets : [
                    {
                        data : (function() {
                            return sum;
                        })()
                    }
            ]
    };
    
    var options = {
            scaleLineWidth : 1
    };
    
    new Chart(ctx).Line(data, options);
}
