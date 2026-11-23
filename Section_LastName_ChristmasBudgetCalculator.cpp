/*
 * ==============================================================
 *  CHRISTMAS PARTY BUDGET CALCULATOR
 *  Final Examination Project - Computer Fundamentals in Programming
 * ==============================================================
 *  Concepts used (Modules 4 and 5 only):
 *    - variables, data types, declaration and initialization
 *    - cin and cout, basic output formatting (iomanip)
 *    - arithmetic, relational, and logical operators
 *    - if, if-else, if-else-if ladder, nested if
 *    - switch statements
 *
 *  NOT used (prohibited): loops, arrays, user-defined functions,
 *  classes/objects.
 *
 *  Because loops are prohibited, the six expense categories are
 *  processed once, in a fixed order: [1] Food -> [2] Drinks ->
 *  [3] Decorations -> [4] Prizes -> [5] Gifts -> [6] Additional,
 *  then [7] the Party Budget Summary is generated.
 *
 *  SDG 4 (Quality Education) / GAD: the program uses gender-neutral,
 *  inclusive wording ("organizer", "guests") and gives clear,
 *  educational feedback so any user can learn good budgeting.
 * ==============================================================
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // ------------------------------------------------------------
    // PARTY INFORMATION
    // ------------------------------------------------------------
    string organizerName = "";
    string partyDate = "";
    int numGuests = 0;
    double availableBudget = 0.0;

    // ------------------------------------------------------------
    // A. FOOD AND CATERING
    // ------------------------------------------------------------
    int foodChoice = 0;
    int foodServings = 0;
    double foodPrice = 0.0;
    double foodCost = 0.0;
    string foodPackage = "None";
    bool foodShort = false;          // true if servings < guests

    // ------------------------------------------------------------
    // B. DRINKS AND BEVERAGES
    // ------------------------------------------------------------
    int drinkChoice = 0;
    int drinkQty = 0;
    double drinkPrice = 0.0;
    double drinkCost = 0.0;
    string drinkName = "None";
    bool drinksShort = false;        // true if drinks < guests

    // ------------------------------------------------------------
    // C. DECORATIONS AND VENUE
    // ------------------------------------------------------------
    int decoChoice = 0;
    int decoQty = 0;
    double decoPrice = 0.0;
    double decoCost = 0.0;
    string decoName = "None";

    // ------------------------------------------------------------
    // D. GAMES AND PRIZES
    // ------------------------------------------------------------
    int prizeChoice = 0;
    int prizeQty = 0;
    double prizePrice = 0.0;
    double prizeCost = 0.0;
    string prizeName = "None";
    string prizeRemark = "N/A";

    // ------------------------------------------------------------
    // E. GIFTS AND EXCHANGE GIFTS
    // ------------------------------------------------------------
    int giftChoice = 0;
    int giftQty = 0;
    double giftPrice = 0.0;
    double giftCost = 0.0;
    string giftName = "None";
    string giftRemark = "N/A";
    bool giftsShort = false;         // true if gifts < guests

    // ------------------------------------------------------------
    // F. ADDITIONAL EXPENSES
    // ------------------------------------------------------------
    double transportCost = 0.0;
    double rentalCost = 0.0;
    double miscCost = 0.0;
    double additionalCost = 0.0;

    // ------------------------------------------------------------
    // BUDGET ANALYSIS
    // ------------------------------------------------------------
    double totalExpenses = 0.0;
    double foodDiscount = 0.0;
    double decoDiscount = 0.0;
    double totalDiscount = 0.0;
    double finalExpenses = 0.0;
    double remainingBalance = 0.0;
    double costPerGuest = 0.0;
    double fortyPercentLimit = 0.0;
    string discountNote = "";
    string budgetStatus = "";
    string budgetClass = "";
    string costClass = "";
    bool invalidEntry = false;       // true if any invalid input was skipped
    bool categoryWarning = false;    // true if any category > 40% of budget

    // Show all money values with 2 decimal places
    cout << fixed << setprecision(2);

    // ============================================================
    // WELCOME SCREEN
    // ============================================================
    cout << "\n";
    cout << "                       *\n";
    cout << "                      /.\\\n";
    cout << "                     /o..\\\n";
    cout << "                     /..o\\\n";
    cout << "                    /.o..o\\\n";
    cout << "                    /...o.\\\n";
    cout << "                   /..o....\\\n";
    cout << "                   ^^^[_]^^^\n";
    cout << "================================================\n";
    cout << "        CHRISTMAS PARTY BUDGET CALCULATOR\n";
    cout << "================================================\n";
    cout << "          Plan Your Christmas Celebration!\n";
    cout << "     A fair and inclusive party for everyone.\n";
    cout << "================================================\n\n";

    cout << "Organizer Name    : ";
    getline(cin, organizerName);

    cout << "Party Date        : ";
    getline(cin, partyDate);

    cout << "Number of Guests  : ";
    cin >> numGuests;

    // Validation: zero or negative number of guests
    if (numGuests <= 0)
    {
        cout << "\nERROR: Number of guests must be greater than zero.\n";
        cout << "Please restart the program and enter a valid number.\n";
        return 1;
    }

    cout << "Available Budget  : PHP ";
    cin >> availableBudget;

    // Validation: zero or negative budget
    if (availableBudget <= 0)
    {
        cout << "\nERROR: Available budget must be greater than zero.\n";
        cout << "Please restart the program and enter a valid budget.\n";
        return 1;
    }

    // ============================================================
    // MAIN MENU (processed in a fixed sequence - no loops allowed)
    // ============================================================
    cout << "\n================================================\n";
    cout << "                   MAIN MENU\n";
    cout << "================================================\n";
    cout << "   [1] Food and Catering Expenses\n";
    cout << "   [2] Drinks and Beverages Expenses\n";
    cout << "   [3] Decorations and Venue Expenses\n";
    cout << "   [4] Games and Prizes Expenses\n";
    cout << "   [5] Gifts and Exchange Gift Expenses\n";
    cout << "   [6] Additional Expenses\n";
    cout << "   [7] Generate Party Budget Summary\n";
    cout << "================================================\n";
    cout << " The program will guide you through [1] to [6]\n";
    cout << " in order, then generate the summary [7].\n";
    cout << "================================================\n";

    // ============================================================
    // [1] FOOD AND CATERING EXPENSES
    // ============================================================
    cout << "\n------------------------------------------------\n";
    cout << " [1] FOOD AND CATERING EXPENSES\n";
    cout << "------------------------------------------------\n";
    cout << "   [1] Basic Christmas Meal      PHP 120.00 / guest\n";
    cout << "   [2] Standard Christmas Meal   PHP 180.00 / guest\n";
    cout << "   [3] Premium Christmas Meal    PHP 250.00 / guest\n";
    cout << "   [4] Deluxe Christmas Meal     PHP 350.00 / guest\n";
    cout << " Enter your choice (1-4): ";
    cin >> foodChoice;

    switch (foodChoice)
    {
        case 1:
            foodPackage = "Basic Christmas Meal";
            foodPrice = 120.00;
            break;
        case 2:
            foodPackage = "Standard Christmas Meal";
            foodPrice = 180.00;
            break;
        case 3:
            foodPackage = "Premium Christmas Meal";
            foodPrice = 250.00;
            break;
        case 4:
            foodPackage = "Deluxe Christmas Meal";
            foodPrice = 350.00;
            break;
        default:
            foodPackage = "None (invalid selection)";
            foodPrice = 0.0;
            invalidEntry = true;
            cout << " ERROR: Invalid food package. Food will NOT be included.\n";
            break;
    }

    if (foodPrice > 0)
    {
        cout << " Enter number of servings: ";
        cin >> foodServings;

        if (foodServings < 0)
        {
            cout << " ERROR: Servings cannot be negative. Food will NOT be included.\n";
            foodServings = 0;
            foodPackage = "None (invalid quantity)";
            invalidEntry = true;
        }
        else
        {
            foodCost = foodPrice * foodServings;
            cout << " Food Cost: PHP " << foodCost << "\n";

            // Sufficiency check
            if (foodServings >= numGuests)
            {
                cout << " Food servings are SUFFICIENT for " << numGuests << " guests.\n";
            }
            else
            {
                cout << " WARNING: Food servings are NOT sufficient! Short by "
                     << (numGuests - foodServings) << " serving(s).\n";
                foodShort = true;
            }

            // Bulk-order message
            if (foodCost >= 5000.00)
            {
                cout << " NOTE: Bulk order! Food expenses reached PHP 5,000.00 (5% discount).\n";
            }
        }
    }

    // ============================================================
    // [2] DRINKS AND BEVERAGES EXPENSES
    // ============================================================
    cout << "\n------------------------------------------------\n";
    cout << " [2] DRINKS AND BEVERAGES EXPENSES\n";
    cout << "------------------------------------------------\n";
    cout << "   [1] Soft Drinks       PHP 25.00 / bottle\n";
    cout << "   [2] Fruit Juice       PHP 30.00 / bottle\n";
    cout << "   [3] Iced Tea          PHP 20.00 / bottle\n";
    cout << "   [4] Bottled Water     PHP 15.00 / bottle\n";
    cout << " Enter your choice (1-4): ";
    cin >> drinkChoice;

    switch (drinkChoice)
    {
        case 1:
            drinkName = "Soft Drinks";
            drinkPrice = 25.00;
            break;
        case 2:
            drinkName = "Fruit Juice";
            drinkPrice = 30.00;
            break;
        case 3:
            drinkName = "Iced Tea";
            drinkPrice = 20.00;
            break;
        case 4:
            drinkName = "Bottled Water";
            drinkPrice = 15.00;
            break;
        default:
            drinkName = "None (invalid selection)";
            drinkPrice = 0.0;
            invalidEntry = true;
            cout << " ERROR: Invalid beverage. Drinks will NOT be included.\n";
            break;
    }

    if (drinkPrice > 0)
    {
        cout << " Enter quantity (bottles): ";
        cin >> drinkQty;

        if (drinkQty < 0)
        {
            cout << " ERROR: Quantity cannot be negative. Drinks will NOT be included.\n";
            drinkQty = 0;
            drinkName = "None (invalid quantity)";
            invalidEntry = true;
        }
        else
        {
            drinkCost = drinkPrice * drinkQty;
            cout << " Drink Cost: PHP " << drinkCost << "\n";

            if (drinkQty < numGuests)
            {
                cout << " WARNING: Drinks are NOT sufficient! Short by "
                     << (numGuests - drinkQty) << " bottle(s).\n";
                drinksShort = true;
            }
            else
            {
                cout << " Drinks are SUFFICIENT for " << numGuests << " guests.\n";
            }
        }
    }

    // ============================================================
    // [3] DECORATIONS AND VENUE EXPENSES
    // ============================================================
    cout << "\n------------------------------------------------\n";
    cout << " [3] DECORATIONS AND VENUE EXPENSES\n";
    cout << "------------------------------------------------\n";
    cout << "   [1] Christmas Lights                  PHP   350.00\n";
    cout << "   [2] Christmas Banner                  PHP   200.00\n";
    cout << "   [3] Christmas Tree                    PHP 1,500.00\n";
    cout << "   [4] Complete Christmas Decoration Set PHP 3,500.00\n";
    cout << " Enter your choice (1-4): ";
    cin >> decoChoice;

    switch (decoChoice)
    {
        case 1:
            decoName = "Christmas Lights";
            decoPrice = 350.00;
            break;
        case 2:
            decoName = "Christmas Banner";
            decoPrice = 200.00;
            break;
        case 3:
            decoName = "Christmas Tree";
            decoPrice = 1500.00;
            break;
        case 4:
            decoName = "Complete Christmas Decoration Set";
            decoPrice = 3500.00;
            break;
        default:
            decoName = "None (invalid selection)";
            decoPrice = 0.0;
            invalidEntry = true;
            cout << " ERROR: Invalid decoration. Decorations will NOT be included.\n";
            break;
    }

    if (decoPrice > 0)
    {
        cout << " Enter quantity: ";
        cin >> decoQty;

        if (decoQty < 0)
        {
            cout << " ERROR: Quantity cannot be negative. Decorations will NOT be included.\n";
            decoQty = 0;
            decoName = "None (invalid quantity)";
            invalidEntry = true;
        }
        else
        {
            decoCost = decoPrice * decoQty;
            cout << " Decoration Cost: PHP " << decoCost << "\n";

            // Special message for the complete set
            if (decoChoice == 4 && decoQty > 0)
            {
                cout << " *** WOW! The Complete Christmas Decoration Set will make\n";
                cout << "     your venue shine with full holiday spirit! ***\n";
            }

            if (decoCost > 3000.00)
            {
                cout << " WARNING: Decoration expenses exceed PHP 3,000.00!\n";
            }
        }
    }

    // ============================================================
    // [4] GAMES AND PRIZES EXPENSES
    // ============================================================
    cout << "\n------------------------------------------------\n";
    cout << " [4] GAMES AND PRIZES EXPENSES\n";
    cout << "------------------------------------------------\n";
    cout << "   [1] Simple Prize Package      PHP   500.00\n";
    cout << "   [2] Standard Prize Package    PHP 1,000.00\n";
    cout << "   [3] Premium Prize Package     PHP 2,000.00\n";
    cout << "   [4] Grand Prize Package       PHP 3,500.00\n";
    cout << " Enter your choice (1-4): ";
    cin >> prizeChoice;

    switch (prizeChoice)
    {
        case 1:
            prizeName = "Simple Prize Package";
            prizePrice = 500.00;
            break;
        case 2:
            prizeName = "Standard Prize Package";
            prizePrice = 1000.00;
            break;
        case 3:
            prizeName = "Premium Prize Package";
            prizePrice = 2000.00;
            break;
        case 4:
            prizeName = "Grand Prize Package";
            prizePrice = 3500.00;
            break;
        default:
            prizeName = "None (invalid selection)";
            prizePrice = 0.0;
            invalidEntry = true;
            cout << " ERROR: Invalid prize package. Prizes will NOT be included.\n";
            break;
    }

    if (prizePrice > 0)
    {
        cout << " Enter number of packages: ";
        cin >> prizeQty;

        if (prizeQty < 0)
        {
            cout << " ERROR: Quantity cannot be negative. Prizes will NOT be included.\n";
            prizeQty = 0;
            prizeName = "None (invalid quantity)";
            invalidEntry = true;
        }
        else
        {
            prizeCost = prizePrice * prizeQty;
            cout << " Prize Cost: PHP " << prizeCost << "\n";

            if (prizeCost >= 2000.00)
            {
                prizeRemark = "Generous Prize Budget";
            }
            else if (prizeCost < 500.00)
            {
                prizeRemark = "Limited Prize Budget";
            }
            else
            {
                prizeRemark = "Moderate Prize Budget";
            }
            cout << " " << prizeRemark << "\n";
        }
    }

    // ============================================================
    // [5] GIFTS AND EXCHANGE GIFT EXPENSES
    // ============================================================
    cout << "\n------------------------------------------------\n";
    cout << " [5] GIFTS AND EXCHANGE GIFT EXPENSES\n";
    cout << "------------------------------------------------\n";
    cout << "   [1] Simple Gift       PHP 100.00 / gift\n";
    cout << "   [2] Standard Gift     PHP 200.00 / gift\n";
    cout << "   [3] Premium Gift      PHP 350.00 / gift\n";
    cout << "   [4] Special Gift      PHP 500.00 / gift\n";
    cout << " Enter your choice (1-4): ";
    cin >> giftChoice;

    switch (giftChoice)
    {
        case 1:
            giftName = "Simple Gift";
            giftPrice = 100.00;
            break;
        case 2:
            giftName = "Standard Gift";
            giftPrice = 200.00;
            break;
        case 3:
            giftName = "Premium Gift";
            giftPrice = 350.00;
            break;
        case 4:
            giftName = "Special Gift";
            giftPrice = 500.00;
            break;
        default:
            giftName = "None (invalid selection)";
            giftPrice = 0.0;
            invalidEntry = true;
            cout << " ERROR: Invalid gift category. Gifts will NOT be included.\n";
            break;
    }

    if (giftPrice > 0)
    {
        cout << " Enter number of gifts: ";
        cin >> giftQty;

        if (giftQty < 0)
        {
            cout << " ERROR: Quantity cannot be negative. Gifts will NOT be included.\n";
            giftQty = 0;
            giftName = "None (invalid quantity)";
            invalidEntry = true;
        }
        else
        {
            giftCost = giftPrice * giftQty;
            cout << " Gift Cost: PHP " << giftCost << "\n";

            if (giftQty == numGuests)
            {
                giftRemark = "Everyone Has a Gift!";
            }
            else if (giftQty < numGuests)
            {
                giftRemark = "Not Enough Gifts!";
                giftsShort = true;
            }
            else
            {
                giftRemark = "Extra Gifts Available!";
            }
            cout << " " << giftRemark << "\n";
        }
    }

    // ============================================================
    // [6] ADDITIONAL EXPENSES
    // ============================================================
    cout << "\n------------------------------------------------\n";
    cout << " [6] ADDITIONAL EXPENSES\n";
    cout << "------------------------------------------------\n";

    cout << " Transportation      : PHP ";
    cin >> transportCost;
    if (transportCost < 0)
    {
        cout << " ERROR: Cost cannot be negative. Transportation set to PHP 0.00.\n";
        transportCost = 0.0;
        invalidEntry = true;
    }

    cout << " Equipment Rental    : PHP ";
    cin >> rentalCost;
    if (rentalCost < 0)
    {
        cout << " ERROR: Cost cannot be negative. Equipment rental set to PHP 0.00.\n";
        rentalCost = 0.0;
        invalidEntry = true;
    }

    cout << " Miscellaneous       : PHP ";
    cin >> miscCost;
    if (miscCost < 0)
    {
        cout << " ERROR: Cost cannot be negative. Miscellaneous set to PHP 0.00.\n";
        miscCost = 0.0;
        invalidEntry = true;
    }

    additionalCost = transportCost + rentalCost + miscCost;
    cout << " Additional Expenses: PHP " << additionalCost << "\n";

    // ============================================================
    // BUDGET ANALYSIS AND CALCULATIONS
    // ============================================================

    // A. Total Expenses
    totalExpenses = foodCost + drinkCost + decoCost + prizeCost + giftCost + additionalCost;

    // B. Discount Computation (nested if)
    if (foodCost >= 5000.00)
    {
        foodDiscount = foodCost * 0.05;

        if (decoCost >= 3000.00)
        {
            decoDiscount = decoCost * 0.03;
            discountNote = "Food (5%) and Decoration (3%) discounts applied";
        }
        else
        {
            discountNote = "Food (5%) discount applied";
        }
    }
    else
    {
        if (decoCost >= 3000.00)
        {
            decoDiscount = decoCost * 0.03;
            discountNote = "Decoration (3%) discount applied";
        }
        else
        {
            discountNote = "No discount applicable";
        }
    }

    totalDiscount = foodDiscount + decoDiscount;
    finalExpenses = totalExpenses - totalDiscount;
    remainingBalance = availableBudget - finalExpenses;

    // C. Budget Status
    if (finalExpenses < availableBudget)
    {
        budgetStatus = "WITHIN BUDGET";
    }
    else if (finalExpenses == availableBudget)
    {
        budgetStatus = "EXACT BUDGET";
    }
    else
    {
        budgetStatus = "OVER BUDGET";
    }

    // D. Budget Classification (if-else-if ladder)
    if (remainingBalance >= 5000.00)
    {
        budgetClass = "EXCELLENT BUDGET MANAGEMENT";
    }
    else if (remainingBalance >= 2000.00)
    {
        budgetClass = "GOOD BUDGET MANAGEMENT";
    }
    else if (remainingBalance > 0.00)
    {
        budgetClass = "LIMITED REMAINING BUDGET";
    }
    else if (remainingBalance == 0.00)
    {
        budgetClass = "FULLY UTILIZED BUDGET";
    }
    else
    {
        budgetClass = "OVER BUDGET";
    }

    // E. Cost Per Guest (with division-by-zero check)
    if (numGuests > 0)
    {
        costPerGuest = finalExpenses / numGuests;

        if (costPerGuest <= 300.00)
        {
            costClass = "ECONOMICAL";
        }
        else if (costPerGuest <= 500.00)
        {
            costClass = "MODERATE";
        }
        else
        {
            costClass = "EXPENSIVE";
        }
    }
    else
    {
        costPerGuest = 0.0;
        costClass = "N/A (cannot divide by zero guests)";
    }

    // F. Additional Budget Warning (more than 40% of budget)
    fortyPercentLimit = availableBudget * 0.40;

    // ============================================================
    // [7] CHRISTMAS PARTY FINANCIAL REPORT
    // ============================================================
    cout << "\n\n====================================================\n";
    cout << "          CHRISTMAS PARTY FINANCIAL REPORT\n";
    cout << "====================================================\n";
    cout << " Organizer        : " << organizerName << "\n";
    cout << " Party Date       : " << partyDate << "\n";
    cout << " Number of Guests : " << numGuests << "\n";
    cout << " Available Budget : PHP " << availableBudget << "\n";

    cout << "----------------------------------------------------\n";
    cout << "                 EXPENSE BREAKDOWN\n";
    cout << "----------------------------------------------------\n";

    cout << " FOOD AND CATERING\n";
    cout << "   Selected Package : " << foodPackage << "\n";
    cout << "   Quantity         : " << foodServings << "\n";
    cout << "   Total            : PHP " << foodCost << "\n";
    cout << "   Discount         : PHP " << foodDiscount << "\n\n";

    cout << " DRINKS AND BEVERAGES\n";
    cout << "   Selected Beverage: " << drinkName << "\n";
    cout << "   Quantity         : " << drinkQty << "\n";
    cout << "   Total            : PHP " << drinkCost << "\n\n";

    cout << " DECORATIONS AND VENUE\n";
    cout << "   Selected Decor   : " << decoName << "\n";
    cout << "   Quantity         : " << decoQty << "\n";
    cout << "   Total            : PHP " << decoCost << "\n";
    cout << "   Discount         : PHP " << decoDiscount << "\n\n";

    cout << " GAMES AND PRIZES\n";
    cout << "   Selected Package : " << prizeName << "\n";
    cout << "   Quantity         : " << prizeQty << "\n";
    cout << "   Total            : PHP " << prizeCost << "\n";
    cout << "   Remark           : " << prizeRemark << "\n\n";

    cout << " GIFTS AND EXCHANGE GIFTS\n";
    cout << "   Selected Gift    : " << giftName << "\n";
    cout << "   Quantity         : " << giftQty << "\n";
    cout << "   Total            : PHP " << giftCost << "\n";
    cout << "   Remark           : " << giftRemark << "\n\n";

    cout << " ADDITIONAL EXPENSES\n";
    cout << "   Transportation   : PHP " << transportCost << "\n";
    cout << "   Equipment Rental : PHP " << rentalCost << "\n";
    cout << "   Miscellaneous    : PHP " << miscCost << "\n";
    cout << "   Total            : PHP " << additionalCost << "\n";

    cout << "----------------------------------------------------\n";
    cout << "                 FINANCIAL SUMMARY\n";
    cout << "----------------------------------------------------\n";
    cout << " Total Expenses        : PHP " << setw(12) << totalExpenses << "\n";
    cout << " Food Discount (5%)    : PHP " << setw(12) << foodDiscount << "\n";
    cout << " Decoration Disc. (3%) : PHP " << setw(12) << decoDiscount << "\n";
    cout << " Total Discounts       : PHP " << setw(12) << totalDiscount << "\n";
    cout << "   (" << discountNote << ")\n";
    cout << " Final Expenses        : PHP " << setw(12) << finalExpenses << "\n\n";
    cout << " Available Budget      : PHP " << setw(12) << availableBudget << "\n";
    cout << " Remaining Balance     : PHP " << setw(12) << remainingBalance << "\n\n";
    cout << " Cost Per Guest        : PHP " << setw(12) << costPerGuest << "\n\n";
    cout << " Budget Status         : " << budgetStatus << "\n";
    cout << " Budget Classification : " << budgetClass << "\n";
    cout << " Cost Classification   : " << costClass << "\n";

    cout << "----------------------------------------------------\n";
    cout << "           WARNINGS AND RECOMMENDATIONS\n";
    cout << "----------------------------------------------------\n";

    // Category over 40% of the available budget
    if (foodCost > fortyPercentLimit)
    {
        cout << " ! Food and Catering uses more than 40% of the budget.\n";
        categoryWarning = true;
    }
    if (drinkCost > fortyPercentLimit)
    {
        cout << " ! Drinks and Beverages uses more than 40% of the budget.\n";
        categoryWarning = true;
    }
    if (decoCost > fortyPercentLimit)
    {
        cout << " ! Decorations and Venue uses more than 40% of the budget.\n";
        categoryWarning = true;
    }
    if (prizeCost > fortyPercentLimit)
    {
        cout << " ! Games and Prizes uses more than 40% of the budget.\n";
        categoryWarning = true;
    }
    if (giftCost > fortyPercentLimit)
    {
        cout << " ! Gifts and Exchange Gifts uses more than 40% of the budget.\n";
        categoryWarning = true;
    }
    if (additionalCost > fortyPercentLimit)
    {
        cout << " ! Additional Expenses uses more than 40% of the budget.\n";
        categoryWarning = true;
    }
    if (!categoryWarning)
    {
        cout << " - No single category exceeds 40% of the budget.\n";
    }

    // Sufficiency warnings
    if (foodShort)
    {
        cout << " ! Food servings are fewer than guests. Add "
             << (numGuests - foodServings) << " more serving(s).\n";
    }
    if (drinksShort)
    {
        cout << " ! Drinks are fewer than guests. Add "
             << (numGuests - drinkQty) << " more bottle(s).\n";
    }
    if (giftsShort)
    {
        cout << " ! Gifts are fewer than guests. Add "
             << (numGuests - giftQty) << " more gift(s) so no one is left out.\n";
    }
    if (decoCost > 3000.00)
    {
        cout << " ! Decoration expenses exceed PHP 3,000.00.\n";
    }
    if (invalidEntry)
    {
        cout << " ! Some entries were invalid and were NOT included in the totals.\n";
    }

    // Budget recommendations (nested if)
    if (remainingBalance < 0)
    {
        cout << " > You are OVER BUDGET by PHP " << (remainingBalance * -1) << ".\n";
        if (costClass == "EXPENSIVE")
        {
            cout << " > Choose cheaper food, gift, or prize packages to lower\n";
            cout << "   the cost per guest.\n";
        }
        else
        {
            cout << " > Reduce quantities or additional expenses to fit the budget.\n";
        }
    }
    else
    {
        if (remainingBalance >= 5000.00)
        {
            cout << " > Great job! Consider saving the extra funds or adding\n";
            cout << "   more activities for your guests.\n";
        }
        else if (remainingBalance > 0)
        {
            cout << " > Keep the remaining balance for emergency expenses.\n";
        }
        else
        {
            cout << " > The budget is fully used. Avoid any extra purchases.\n";
        }
    }

    cout << "\n====================================================\n";
    cout << "          YOUR CHRISTMAS PARTY IS READY!\n";
    cout << "               MERRY CHRISTMAS, " << organizerName << "!\n";
    cout << "====================================================\n";

    return 0;
}
