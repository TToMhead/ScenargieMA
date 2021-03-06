/ /   C o p y r i g h t   ( c )   2 0 0 7 - 2 0 1 7   b y   S p a c e - T i m e   E n g i n e e r i n g ,   L L C   ( " S T E " ) . 
 / /   A l l   R i g h t s   R e s e r v e d . 
 / / 
 / /   T h i s   s o u r c e   c o d e   i s   a   p a r t   o f   S c e n a r g i e   S o f t w a r e   ( " S o f t w a r e " )   a n d   i s 
 / /   s u b j e c t   t o   S T E   S o f t w a r e   L i c e n s e   A g r e e m e n t .   T h e   i n f o r m a t i o n   c o n t a i n e d 
 / /   h e r e i n   i s   c o n s i d e r e d   a   t r a d e   s e c r e t   o f   S T E ,   a n d   m a y   n o t   b e   u s e d   a s 
 / /   t h e   b a s i s   f o r   a n y   o t h e r   s o f t w a r e ,   h a r d w a r e ,   p r o d u c t   o r   s e r v i c e . 
 / / 
 / /   R e f e r   t o   l i c e n s e . t x t   f o r   m o r e   s p e c i f i c   d i r e c t i v e s . 
 
 # i n c l u d e   " m u l t i a g e n t _ a g e n t s i m . h " 
 # i n c l u d e   " m u l t i a g e n t _ p u b l i c v e h i c l e . h " 
 # i n c l u d e   " m u l t i a g e n t _ b e h a v i o r . h " 
 # i n c l u d e   " m u l t i a g e n t _ r o u t e s e a r c h . h " 
 # i n c l u d e   " m u l t i a g e n t _ g i s . h " 
 # i n c l u d e   " m u l t i a g e n t _ e x t e n s i o n . h " 
 # i n c l u d e   " m u l t i a g e n t _ n e t w o r k i n t e r f a c e . h " 
 # i n c l u d e   " m u l t i a g e n t _ t r a c e d e f s . h " 
 # i n c l u d e   " b o o s t / f i l e s y s t e m . h p p " 
 
 n a m e s p a c e   M u l t i A g e n t   { 
 
 # i f d e f   M U L T I A G E N T _ D E B U G 
 c o n s t   b o o l   M u l t i A g e n t S i m u l a t o r : : i s D e b u g M o d e   =   t r u e ; 
 # e l s e 
 c o n s t   b o o l   M u l t i A g e n t S i m u l a t o r : : i s D e b u g M o d e   =   f a l s e ; 
 # e n d i f 
 
 A g e n t R e s o u r c e   A d d A g e n t s [ 1 0 0 ] ; 
 b o o l   t r i n i n e   =   f a l s e ; 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 c l a s s   A g e n t M o b i l i t y M o d e l   :   p u b l i c   O b j e c t M o b i l i t y M o d e l   { 
 p u b l i c : 
         A g e n t M o b i l i t y M o d e l ( c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e )   :   r e s o u r c e ( i n i t R e s o u r c e )   { } 
 
         v i r t u a l   v o i d   G e t U n a d j u s t e d P o s i t i o n F o r T i m e ( 
                 c o n s t   S i m T i m e &   s n a p s h o t T i m e ,   O b j e c t M o b i l i t y P o s i t i o n &   p o s i t i o n )   o v e r r i d e 
         { 
                 p o s i t i o n   =   r e s o u r c e . M o b i l i t y P o s i t i o n F o r T i m e ( s n a p s h o t T i m e ) ; 
         } 
 p r i v a t e : 
         A g e n t R e s o u r c e   r e s o u r c e ; 
 } ; 
 
 c l a s s   V e h i c l e M o b i l i t y M o d e l   :   p u b l i c   O b j e c t M o b i l i t y M o d e l   { 
 p u b l i c : 
         V e h i c l e M o b i l i t y M o d e l ( c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d )   :   a g e n t I d ( i n i t A g e n t I d )   { } 
 
         v o i d   S e t P u b l i c V e h i c l e ( c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e > &   p u b l i c V e h i c l e P t r )   { 
                 v e h i c l e A c c e s s P t r . r e s e t ( n e w   P u b l i c V e h i c l e A c c e s s ( p u b l i c V e h i c l e P t r ) ) ; 
         } 
         v o i d   S e t V e h i c l e ( c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r )   { 
                 v e h i c l e A c c e s s P t r . r e s e t ( n e w   V e h i c l e A c c e s s ( v e h i c l e P t r ,   V E H I C L E _ C A R ) ) ; 
         } 
         v o i d   S e t T a x i ( c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r )   { 
                 v e h i c l e A c c e s s P t r . r e s e t ( n e w   V e h i c l e A c c e s s ( v e h i c l e P t r ,   V E H I C L E _ T A X I ) ) ; 
         } 
 
         V e h i c l e T y p e   G e t V e h i c l e T y p e ( )   c o n s t   {   r e t u r n   v e h i c l e A c c e s s P t r - > G e t V e h i c l e T y p e ( ) ;   } 
 
         v i r t u a l   v o i d   G e t U n a d j u s t e d P o s i t i o n F o r T i m e ( 
                 c o n s t   S i m T i m e &   s n a p s h o t T i m e , 
                 O b j e c t M o b i l i t y P o s i t i o n &   p o s i t i o n )   o v e r r i d e 
         { 
                 p o s i t i o n   =   ( * t h i s ) . G e t C u r r e n t L o c a t i o n ( s n a p s h o t T i m e ) ; 
         } 
 
         O b j e c t M o b i l i t y P o s i t i o n   G e t C u r r e n t L o c a t i o n ( c o n s t   S i m T i m e &   c u r r e n t T i m e )   c o n s t   { 
                 c o n s t   V e r t e x   c u r r e n t P o s i t i o n   =   v e h i c l e A c c e s s P t r - > G e t P o s i t i o n ( ) ; 
                 c o n s t   d o u b l e   a z i m u t h D e g r e e s   =   v e h i c l e A c c e s s P t r - > G e t D i r e c t i o n R a d i a n s ( ) * ( 1 8 0 . / P I ) ; 
 
                 r e t u r n   O b j e c t M o b i l i t y P o s i t i o n ( 
                         c u r r e n t T i m e , 
                         c u r r e n t T i m e , 
                         c u r r e n t P o s i t i o n . x , 
                         c u r r e n t P o s i t i o n . y , 
                         c u r r e n t P o s i t i o n . z , 
                         t r u e / * t h e H e i g h t C o n t a i n s G r o u n d H e i g h t M e t e r s * / , 
                         9 0   -   a z i m u t h D e g r e e s , 
                         0 . 0 ,   0 . 0 ,   0 . 0 ,   0 . 0 ) ; 
         } 
 
 p r i v a t e : 
         c l a s s   A b s t r a c t V e h i c l e A c c e s s   { 
         p u b l i c : 
                 v i r t u a l   ~ A b s t r a c t V e h i c l e A c c e s s ( )   { } 
                 v i r t u a l   c o n s t   V e r t e x &   G e t P o s i t i o n ( )   c o n s t   =   0 ; 
                 v i r t u a l   d o u b l e   G e t D i r e c t i o n R a d i a n s ( )   c o n s t   =   0 ; 
                 v i r t u a l   V e h i c l e T y p e   G e t V e h i c l e T y p e ( )   c o n s t   =   0 ; 
         } ; 
 
         c l a s s   P u b l i c V e h i c l e A c c e s s   :   p u b l i c   A b s t r a c t V e h i c l e A c c e s s   { 
         p u b l i c : 
                 P u b l i c V e h i c l e A c c e s s ( c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e > &   i n i t P u b l i c V e h i c l e P t r )   :   p u b l i c V e h i c l e P t r ( i n i t P u b l i c V e h i c l e P t r )   { } 
                 v i r t u a l   c o n s t   V e r t e x &   G e t P o s i t i o n ( )   c o n s t   {   r e t u r n   p u b l i c V e h i c l e P t r - > G e t P o s i t i o n ( ) ;   } 
                 v i r t u a l   d o u b l e   G e t D i r e c t i o n R a d i a n s ( )   c o n s t   {   r e t u r n   p u b l i c V e h i c l e P t r - > G e t D i r e c t i o n R a d i a n s ( ) ;   } 
                 v i r t u a l   V e h i c l e T y p e   G e t V e h i c l e T y p e ( )   c o n s t   {   r e t u r n   p u b l i c V e h i c l e P t r - > G e t V e h i c l e T y p e ( ) ;   } 
         p r i v a t e : 
                 s h a r e d _ p t r < P u b l i c V e h i c l e >   p u b l i c V e h i c l e P t r ; 
         } ; 
 
         c l a s s   V e h i c l e A c c e s s   :   p u b l i c   A b s t r a c t V e h i c l e A c c e s s   { 
         p u b l i c : 
                 V e h i c l e A c c e s s ( 
                         c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r , 
                         c o n s t   V e h i c l e T y p e &   i n i t V e h i c l e T y p e ) 
                         : 
                         v e h i c l e P t r ( i n i t V e h i c l e P t r ) , 
                         v e h i c l e T y p e ( i n i t V e h i c l e T y p e ) 
                 { } 
 
                 v i r t u a l   c o n s t   V e r t e x &   G e t P o s i t i o n ( )   c o n s t   {   r e t u r n   v e h i c l e P t r - > G e t P o s i t i o n ( ) ;   } 
                 v i r t u a l   d o u b l e   G e t D i r e c t i o n R a d i a n s ( )   c o n s t   {   r e t u r n   v e h i c l e P t r - > G e t D i r e c t i o n R a d i a n s ( ) ;   } 
                 v i r t u a l   V e h i c l e T y p e   G e t V e h i c l e T y p e ( )   c o n s t   {   r e t u r n   v e h i c l e T y p e ;   } 
         p r i v a t e : 
                 s h a r e d _ p t r < V e h i c l e >   v e h i c l e P t r ; 
                 V e h i c l e T y p e   v e h i c l e T y p e ; 
         } ; 
 
         A g e n t I d T y p e   a g e n t I d ; 
         s h a r e d _ p t r < A b s t r a c t V e h i c l e A c c e s s >   v e h i c l e A c c e s s P t r ; 
 } ; 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 c l a s s   A g e n t N o d e   :   p u b l i c   N e t w o r k N o d e   { 
 p u b l i c : 
         A g e n t N o d e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   G l o b a l N e t w o r k i n g O b j e c t B a g &   t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                 c o n s t   s h a r e d _ p t r < S c e n S i m : : G i s S u b s y s t e m > &   t h e G i s S u b s y s t e m P t r , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m u l a t i o n E n g i n e I n t e r f a c e P t r , 
                 c o n s t   N o d e I d &   t h e N o d e I d , 
                 c o n s t   R a n d o m N u m b e r G e n e r a t o r S e e d &   r u n S e e d , 
                 c o n s t   s h a r e d _ p t r < O b j e c t M o b i l i t y M o d e l > &   i n i t N o d e M o b i l i t y M o d e l P t r , 
                 c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) ; 
 
         v i r t u a l   c o n s t   O b j e c t M o b i l i t y P o s i t i o n   G e t C u r r e n t L o c a t i o n ( )   c o n s t   { 
 
                 c o n s t   O b j e c t M o b i l i t y P o s i t i o n   p o s i t i o n   =   r e s o u r c e . M o b i l i t y P o s i t i o n ( ) ; 
 
                 i f   ( p o s i t i o n . X _ P o s i t i o n M e t e r s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . X _ P o s i t i o n M e t e r s ( )   | | 
                         p o s i t i o n . Y _ P o s i t i o n M e t e r s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . Y _ P o s i t i o n M e t e r s ( )   | | 
                         p o s i t i o n . H e i g h t F r o m G r o u n d M e t e r s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . H e i g h t F r o m G r o u n d M e t e r s ( )   | | 
                         p o s i t i o n . A t t i t u d e A z i m u t h F r o m N o r t h C l o c k w i s e D e g r e e s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . A t t i t u d e A z i m u t h F r o m N o r t h C l o c k w i s e D e g r e e s ( ) )   { 
                         l a s t M o b i l i t y P o s i t i o n   =   p o s i t i o n ; 
                 } 
 
                 r e t u r n   l a s t M o b i l i t y P o s i t i o n ; 
         } 
 
 p r i v a t e : 
         A g e n t R e s o u r c e   r e s o u r c e ; 
         m u t a b l e   O b j e c t M o b i l i t y P o s i t i o n   l a s t M o b i l i t y P o s i t i o n ; 
 } ; 
 
 c l a s s   V e h i c l e N o d e   :   p u b l i c   A g e n t N o d e   { 
 p u b l i c : 
         V e h i c l e N o d e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   G l o b a l N e t w o r k i n g O b j e c t B a g &   t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                 c o n s t   s h a r e d _ p t r < S c e n S i m : : G i s S u b s y s t e m > &   t h e G i s S u b s y s t e m P t r , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m u l a t i o n E n g i n e I n t e r f a c e P t r , 
                 c o n s t   N o d e I d &   t h e N o d e I d , 
                 c o n s t   R a n d o m N u m b e r G e n e r a t o r S e e d &   r u n S e e d , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e M o b i l i t y M o d e l > &   i n i t N o d e M o b i l i t y M o d e l P t r ) 
                 : 
                 A g e n t N o d e ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                         t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                         t h e G i s S u b s y s t e m P t r , 
                         i n i t S i m u l a t i o n E n g i n e I n t e r f a c e P t r , 
                         t h e N o d e I d , 
                         r u n S e e d , 
                         i n i t N o d e M o b i l i t y M o d e l P t r , 
                         A g e n t R e s o u r c e ( ) ) , 
                 m o b i l i t y M o d e l P t r ( i n i t N o d e M o b i l i t y M o d e l P t r ) 
         { } 
 
         v o i d   S e t P u b l i c V e h i c l e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   S i m T i m e &   c u r r e n t T i m e , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e > &   p u b l i c V e h i c l e P t r )   { 
 
                 m o b i l i t y M o d e l P t r - > S e t P u b l i c V e h i c l e ( p u b l i c V e h i c l e P t r ) ; 
 
                 ( * t h i s ) . E n a b l e M o v i n g O b j e c t s ( t h e P a r a m e t e r D a t a b a s e R e a d e r ,   t h e A g e n t G i s P t r ,   c u r r e n t T i m e ) ; 
 
         } 
         v o i d   S e t V e h i c l e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   S i m T i m e &   c u r r e n t T i m e , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r )   { 
 
                 m o b i l i t y M o d e l P t r - > S e t V e h i c l e ( v e h i c l e P t r ) ; 
 
                 ( * t h i s ) . E n a b l e M o v i n g O b j e c t s ( t h e P a r a m e t e r D a t a b a s e R e a d e r ,   t h e A g e n t G i s P t r ,   c u r r e n t T i m e ) ; 
         } 
         v o i d   S e t T a x i ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   S i m T i m e &   c u r r e n t T i m e , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r )   { 
 
                 m o b i l i t y M o d e l P t r - > S e t T a x i ( v e h i c l e P t r ) ; 
 
                 ( * t h i s ) . E n a b l e M o v i n g O b j e c t s ( t h e P a r a m e t e r D a t a b a s e R e a d e r ,   t h e A g e n t G i s P t r ,   c u r r e n t T i m e ) ; 
         } 
 
         A g e n t I d T y p e   G e t A g e n t I d ( )   c o n s t   {   r e t u r n   ( * t h i s ) . G e t N o d e I d ( ) ;   } 
 
         V e h i c l e T y p e   G e t V e h i c l e T y p e ( )   c o n s t   {   r e t u r n   m o b i l i t y M o d e l P t r - > G e t V e h i c l e T y p e ( ) ;   } 
 
         v i r t u a l   c o n s t   O b j e c t M o b i l i t y P o s i t i o n   G e t C u r r e n t L o c a t i o n ( )   c o n s t   { 
 
                 c o n s t   O b j e c t M o b i l i t y P o s i t i o n   p o s i t i o n   =   m o b i l i t y M o d e l P t r - > G e t C u r r e n t L o c a t i o n ( s i m u l a t i o n E n g i n e I n t e r f a c e P t r - > C u r r e n t T i m e ( ) ) ; 
 
                 i f   ( p o s i t i o n . X _ P o s i t i o n M e t e r s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . X _ P o s i t i o n M e t e r s ( )   | | 
                         p o s i t i o n . Y _ P o s i t i o n M e t e r s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . Y _ P o s i t i o n M e t e r s ( )   | | 
                         p o s i t i o n . H e i g h t F r o m G r o u n d M e t e r s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . H e i g h t F r o m G r o u n d M e t e r s ( )   | | 
                         p o s i t i o n . A t t i t u d e A z i m u t h F r o m N o r t h C l o c k w i s e D e g r e e s ( )   ! =   l a s t M o b i l i t y P o s i t i o n . A t t i t u d e A z i m u t h F r o m N o r t h C l o c k w i s e D e g r e e s ( ) )   { 
                         l a s t M o b i l i t y P o s i t i o n   =   p o s i t i o n ; 
                 } 
 
                 r e t u r n   l a s t M o b i l i t y P o s i t i o n ; 
         } 
 
 p r i v a t e : 
         v o i d   E n a b l e M o v i n g O b j e c t s ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   S i m T i m e &   c u r r e n t T i m e )   { 
 
                 G i s S u b s y s t e m &   g i s S u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
                 g i s S u b s y s t e m . R e m o v e M o v i n g O b j e c t ( t h e N o d e I d ) ; 
                 g i s S u b s y s t e m . E n a b l e M o v i n g O b j e c t I f N e c e s s a r y ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                         t h e N o d e I d , 
                         c u r r e n t T i m e , 
                         m o b i l i t y M o d e l P t r ) ; 
         } 
 
         s h a r e d _ p t r < V e h i c l e M o b i l i t y M o d e l >   m o b i l i t y M o d e l P t r ; 
         m u t a b l e   O b j e c t M o b i l i t y P o s i t i o n   l a s t M o b i l i t y P o s i t i o n ; 
 } ; 
 
 i n l i n e 
 A g e n t N o d e : : A g e n t N o d e ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   G l o b a l N e t w o r k i n g O b j e c t B a g &   t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
         c o n s t   s h a r e d _ p t r < S c e n S i m : : G i s S u b s y s t e m > &   t h e G i s S u b s y s t e m P t r , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m u l a t i o n E n g i n e I n t e r f a c e P t r , 
         c o n s t   N o d e I d &   t h e N o d e I d , 
         c o n s t   R a n d o m N u m b e r G e n e r a t o r S e e d &   r u n S e e d , 
         c o n s t   s h a r e d _ p t r < O b j e c t M o b i l i t y M o d e l > &   i n i t N o d e M o b i l i t y M o d e l P t r , 
         c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
         : 
         N e t w o r k N o d e ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                 i n i t S i m u l a t i o n E n g i n e I n t e r f a c e P t r , 
                 i n i t N o d e M o b i l i t y M o d e l P t r , 
                 t h e N o d e I d , 
                 r u n S e e d ) , 
         r e s o u r c e ( i n i t R e s o u r c e ) 
 { } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 b o o l   A S t r i n g S t a r t s W i t h ( c o n s t   s t r i n g &   a L i n e ,   c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         r e t u r n   ( a L i n e . f i n d ( a S t r i n g )   = =   0 ) ; 
 } 
 
 s t a t i c   i n l i n e 
 b o o l   I s N a t u r a l N u m b e r ( c o n s t   d o u b l e   a V a l u e ) 
 { 
         d o u b l e   i n t P a r t ; 
         d o u b l e   f l o a t P a r t ; 
 
         f l o a t P a r t   =   m o d f ( a V a l u e ,   & i n t P a r t ) ; 
 
         i f   ( i n t P a r t   < =   0 . 0 )   { 
                 r e t u r n   f a l s e ; 
         } / / i f / / 
 
         r e t u r n   ( f a b s ( f l o a t P a r t )   <   D B L _ E P S I L O N ) ; 
 } / / I s N a t u r a l N u m b e r / / 
 
 c o n s t   s t r i n g   A g e n t : : m o d e l N a m e   =   " M a s " ; 
 
 A g e n t : : A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   G l o b a l N e t w o r k i n g O b j e c t B a g &   i n i t G l o b a l N e t w o r k i n g O b j e c t B a g , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r ) 
         : 
         s i m u l a t o r P t r ( i n i t S i m u l a t o r P t r ) , 
         t h e A g e n t G i s P t r ( i n i t A g e n t G i s P t r ) , 
         t h e P u b l i c V e h i c l e T a b l e P t r ( i n i t P u b l i c V e h i c l e T a b l e P t r ) , 
         t h e R o u t e S e a r c h S u b s y s t e m P t r ( i n i t R o u t e S e a r c h S u b s y s t e m P t r ) , 
         a g e n t I d ( i n i t A g e n t I d ) , 
         s i m E n g i n e I n t e r f a c e P t r ( i n i t S i m E n g i n e I n t e r f a c e P t r ) , 
         p r o f i l e P t r ( i n i t P r o f i l e P t r ) , 
         t a s k T a b l e P t r ( i n i t T a s k T a b l e P t r ) , 
         i s D e l e t e d A t T h e E n d O f T i m e S t e p ( f a l s e ) , 
         h a s B i c y c l e ( f a l s e ) , 
         c u r r e n t T a s k S t a r t T i m e ( Z E R O _ T I M E ) , 
         c u r r e n t T a s k E n d T i m e ( Z E R O _ T I M E ) , 
         i s T a s k I n i t i a l i z e d ( f a l s e ) , 
         c u r r e n t T a s k N u m b e r ( 0 ) , 
         c u r r e n t I s I n t e r r u p t T a s k ( f a l s e ) , 
         c u r r e n t I n t e r r u p t T a s k N u m b e r ( 0 ) , 
         d e s t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e ( f a l s e ) , 
         c u r r e n t R o u t e N u m b e r ( N O _ R O U T E _ N U M B E R ) , 
         l a s t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         e n t r a n c e W a i t S t a r t T i m e ( I N F I N I T E _ T I M E ) , 
         d i r e c t i o n R a d i a n s ( 0 ) , 
         c u r r e n t B e h a v i o r S t a r t T i m e ( Z E R O _ T I M E ) , 
         l a s t R o u t e C a l c u l a t e d T i m e ( Z E R O _ T I M E ) , 
         l a s t P a t h Q u e r y T r i g g e r T i m e ( Z E R O _ T I M E ) , 
         r e c a l c u l a t e R o u t e ( f a l s e ) , 
         r e c a l c u l a t e R o u t e W i t h B e h a v i o r ( A G E N T _ B E H A V I O R _ A N Y ) , 
         l a s t D e l a y ( Z E R O _ T I M E ) , 
         u t i l i t y 1 C a l c u l a t i o n C o u n t ( 0 ) , 
         u t i l i t y 2 C a l c u l a t i o n C o u n t ( 0 ) , 
         a R a n d o m N u m b e r G e n e r a t o r ( 
                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ,   S E E D _ H A S H I N G ) ) , 
         a R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ( 
                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ,   S E E D _ H A S H I N G _ F O R _ D E S T I N A T I O N _ C H O I C E ) ) , 
         p a r e n t A g e n t I d ( M A S T E R _ A N Y _ A G E N T _ I D ) , 
         u t i l i t y 1 S t a t P t r ( 
                 s i m E n g i n e I n t e r f a c e P t r - > C r e a t e R e a l S t a t ( m o d e l N a m e   +   " _ U t i l i t y 1 " ) ) , 
         u t i l i t y 2 S t a t P t r ( 
                 s i m E n g i n e I n t e r f a c e P t r - > C r e a t e R e a l S t a t ( m o d e l N a m e   +   " _ U t i l i t y 2 " ) ) , 
         t r a v e l D i s t a n c e S t a t P t r ( 
                 s i m E n g i n e I n t e r f a c e P t r - > C r e a t e R e a l S t a t ( m o d e l N a m e   +   " _ T r a v e l D i s t a n c e " ) ) , 
         t r a v e l T i m e S t a t P t r ( 
                 s i m E n g i n e I n t e r f a c e P t r - > C r e a t e R e a l S t a t ( m o d e l N a m e   +   " _ T r a v e l T i m e " ) ) , 
         n u m b e r N o R o u t e S t a t P t r ( 
                 s i m E n g i n e I n t e r f a c e P t r - > C r e a t e C o u n t e r S t a t ( m o d e l N a m e   +   " _ N o R o u t e s " ) ) , 
         n u m b e r R o u t e C a l c u l a t e T i m e S t a t P t r ( 
                 s i m E n g i n e I n t e r f a c e P t r - > C r e a t e C o u n t e r S t a t ( m o d e l N a m e   +   " _ R o u t e C a l c u l a t i o n T i m e s " ) ) , 
         u t i l i t y 1 T r a c e ( 0 . ) , 
         u t i l i t y 2 T r a c e ( 0 . ) , 
         c o n g e s t i o n T r a c e ( 0 . ) , 
         t r a v e l D i s t a n c e T r a c e ( 0 . ) , 
         t r a v e l T i m e T r a c e ( 0 . ) , 
         d e s t i n a t i o n C h a n g e T r a c e ( 0 ) , 
         l a s t T i m e s t e p B e h a v i o r T y p e ( A G E N T _ B E H A V I O R _ N O T H I N G ) 
 { 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
         b o o l   i s S p e c i f i e d P o s i t i o n ; 
         V e r t e x   p o s i t i o n ; 
 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r   r a n d G e n ( 
                 H a s h I n p u t s T o M a k e S e e d ( 
                         s i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) , 
                         a g e n t I d , 
                         S E E D _ H A S H I N G _ F O R _ S C E N A R I O _ G E N E R A T I O N _ L O C A T I O N _ I N I T ) ) ; 
 
         t a s k T a b l e P t r - > G e t I n i t i a l L o c a t i o n I d ( 
                 s i m u l a t o r P t r - > G e t P a r a m e t e r D a t a b a s e R e a d e r ( ) , 
                 t h e A g e n t G i s P t r , 
                 s i m u l a t o r P t r - > G e t I n i t i a l L o c a t i o n F i l e C a c h e P t r ( ) , 
                 h o m e P o s i t i o n I d , 
                 i s S p e c i f i e d P o s i t i o n , 
                 p o s i t i o n , 
                 r e s o u r c e , 
                 r a n d G e n ) ; 
 
         c u r r e n t P o s i t i o n I d   =   h o m e P o s i t i o n I d ; 
         d e s i r e d N e x t P o s i t i o n I d   =   c u r r e n t P o s i t i o n I d ; 
 
         R o a d I d T y p e   r o a d I d ; 
 
         i f   ( c u r r e n t P o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G )   { 
                 c o n s t   B u i l d i n g &   b u i l d i n g   =   s u b s y s t e m . G e t B u i l d i n g ( c u r r e n t P o s i t i o n I d . i d ) ; 
                 i f   ( ! i s S p e c i f i e d P o s i t i o n )   { 
                         p o s i t i o n   =   b u i l d i n g . G e t R a n d o m P o s i t i o n ( r a n d G e n ) ; 
                 } / / i f / / 
 
                 l a s t V e r t e x I d   =   b u i l d i n g . G e t N e a r e s t E n t r a n c e V e r t e x I d ( p o s i t i o n ) ; 
                 r o a d I d   =   b u i l d i n g . G e t N e a r e s t E n t r a n c e R o a d I d ( p o s i t i o n ) ; 
 
         }   e l s e   i f   ( c u r r e n t P o s i t i o n I d . t y p e   = =   G I S _ P A R K )   { 
 
                 c o n s t   P a r k &   p a r k   =   s u b s y s t e m . G e t P a r k ( c u r r e n t P o s i t i o n I d . i d ) ; 
 
                 i f   ( ! i s S p e c i f i e d P o s i t i o n )   { 
                         p o s i t i o n   =   p a r k . G e t R a n d o m P o s i t i o n ( r a n d G e n ) ; 
                 } / / i f / / 
 
                 l a s t V e r t e x I d   =   p a r k . G e t N e a r e s t E n t r a n c e V e r t e x I d ( p o s i t i o n ) ; 
                 r o a d I d   =   p a r k . G e t N e a r e s t E n t r a n c e R o a d I d ( p o s i t i o n ) ; 
         }   e l s e   { 
                 a s s e r t ( c u r r e n t P o s i t i o n I d . t y p e   = =   G I S _ P O I ) ; 
 
                 c o n s t   P o i &   p o i   =   s u b s y s t e m . G e t P o i ( c u r r e n t P o s i t i o n I d . i d ) ; 
 
                 i f   ( ! i s S p e c i f i e d P o s i t i o n )   { 
                         p o s i t i o n   =   p o i . G e t V e r t e x ( ) ; 
                 } / / i f / / 
 
                 l a s t V e r t e x I d   =   p o i . G e t V e r t e x I d ( ) ; 
                 r o a d I d   =   p o i . G e t N e a r e s t E n t r a n c e R o a d I d ( p o s i t i o n ) ; 
         } 
         p o s i t i o n . z   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t G r o u n d E l e v a t i o n M e t e r s A t ( p o s i t i o n ) ; 
 
         s t a t u s . c u r r e n t P o s i t i o n   =   p o s i t i o n ; 
         s t a t u s . n e x t P o s i t i o n   =   s t a t u s . c u r r e n t P o s i t i o n ; 
 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s   =   p r o f i l e P t r - > G e t P a r a m e t e r s ( ) ; 
 
         b o o l   h a s C a r ; 
 
         ( * t h i s ) . I n i t i a l i z e S t a t u s W i t h ( p a r a m e t e r s ,   t r u e / * c a l c u l a t e C a r A n d B i c y c l e P r o b a b i l i t y * / ,   h a s C a r ) ; 
 
         i f   ( ! I s N a t u r a l N u m b e r ( s t a t u s . v a l u e s [ A G E N T _ R E S E R V E D _ N U M B E R _ P E O P L E ] ) )   { 
                 c e r r   < <   " E r r o r   :   \ " N u m b e r O f P e o p l e \ "   m u s t   b e   a   n a t u r a l   n u m b e r   i n   A g e n t P r o f i l e . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f . . 
 
         i f   ( h a s C a r )   { 
                 c o n s t   R o a d &   r o a d   =   s u b s y s t e m . G e t R o a d ( r o a d I d ) ; 
                 c o n s t   s i z e _ t   p o i L a n e N u m b e r   =   r o a d . G e t P a r k i n g L a n e N u m b e r ( ) ; 
 
                 v e h i c l e P t r . r e s e t ( 
                         n e w   V e h i c l e ( 
                                 a g e n t I d , 
                                 l a s t V e r t e x I d , 
                                 s u b s y s t e m . G e t V e r t e x ( l a s t V e r t e x I d ) , 
                                 r o a d I d , 
                                 p o i L a n e N u m b e r , 
                                 s i m u l a t o r P t r ) ) ; 
 
                 i f   ( r o a d . I s B u i l d i n g P a r k i n g R o a d ( ) )   { 
                         c o n s t   B u i l d i n g I d T y p e   b u i l d i n g I d   =   r o a d . G e t B u i l d i n g I d ( ) ; 
 
                         t h e A g e n t G i s P t r - > P l a c e I n i t i a l V e h i c l e ( r e s o u r c e ,   b u i l d i n g I d ) ; 
                 } / / i f / / 
         } / / i f / / 
 
         t a s k T a b l e P t r - > G e t S t a t u s C h a n g e s ( r e s o u r c e ,   t i m e L i n e S t a t u s C h a n g e E v e n t s ) ; 
 
         m o b i l i t y M o d e l P t r . r e s e t ( n e w   A g e n t M o b i l i t y M o d e l ( r e s o u r c e ) ) ; 
 
         c o n s t   b o o l   e n a b l e H u m a n T a l k i n g I n t e r f a c e   =   f a l s e ; 
 
         i f   ( e n a b l e H u m a n T a l k i n g I n t e r f a c e )   { 
                 h u m a n I n t e r f a c e P t r   = 
                         i n i t G l o b a l N e t w o r k i n g O b j e c t B a g . s e n s i n g S u b s y s t e m I n t e r f a c e P t r - > C r e a t e S h a p e S e n s i n g M o d e l ( 
                                 i n i t S i m E n g i n e I n t e r f a c e P t r , 
                                 a g e n t I d , 
                                 " h u m a n t a l k " , 
                                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ) ) ; 
 
                 h u m a n I n t e r f a c e P t r - > S e t D a t a R e c e i v e H a n d l e r ( 
                         s h a r e d _ p t r < S e n s i n g M o d e l : : D a t a R e c e i v e H a n d l e r > ( 
                                 n e w   P h y s i c a l D a t a R e c e i v e r ( A g e n t R e s o u r c e ( t h i s ) ) ) ) ; 
 
 
                 s h a r e d _ p t r < F a n S e n s i n g S h a p e >   f a n S e n s i n g S h a p e P t r ( n e w   F a n S e n s i n g S h a p e ( ) ) ; 
 
                 / /   a s s u m e   t a l k i n g   i n t e r f a c e   f o r   t h i s   i n s t a n c e . 
                 f a n S e n s i n g S h a p e P t r - > S e t C o v e r a g e D i s t a n c e M e t e r s ( 1 0 0 / * t a l k i n g   r a n g e   1 0 m * / ) ; 
                 f a n S e n s i n g S h a p e P t r - > S e t H o r i z o n t a l C o v e r a g e F r o m B o r e s i g h t D e g r e e s ( 
                         1 3 5 / * - 1 3 5   < =   t a l l k i n g   r a n g e   < =   +   1 3 5 * / ) ; 
 
                 h u m a n I n t e r f a c e P t r - > S e t S e n s i n g S h a p e ( f a n S e n s i n g S h a p e P t r ) ; 
         } 
 
         d e s t i n a t i o n C h a n g e T r a c e . U n s e t C h a n g e F l a g ( ) ; 
 } 
 
 A g e n t : : A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
         c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
         c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r ) 
         : 
         s i m u l a t o r P t r ( i n i t S i m u l a t o r P t r ) , 
         t h e A g e n t G i s P t r ( i n i t A g e n t G i s P t r ) , 
         t h e P u b l i c V e h i c l e T a b l e P t r ( i n i t P u b l i c V e h i c l e T a b l e P t r ) , 
         t h e R o u t e S e a r c h S u b s y s t e m P t r ( i n i t R o u t e S e a r c h S u b s y s t e m P t r ) , 
         a g e n t I d ( i n i t A g e n t I d ) , 
         s i m E n g i n e I n t e r f a c e P t r ( i n i t S i m E n g i n e I n t e r f a c e P t r ) , 
         p r o f i l e P t r ( i n i t P r o f i l e P t r ) , 
         t a s k T a b l e P t r ( i n i t T a s k T a b l e P t r ) , 
         i s D e l e t e d A t T h e E n d O f T i m e S t e p ( f a l s e ) , 
         c u r r e n t T a s k S t a r t T i m e ( Z E R O _ T I M E ) , 
         c u r r e n t T a s k E n d T i m e ( I N F I N I T E _ T I M E ) , 
         i s T a s k I n i t i a l i z e d ( t r u e ) , 
         c u r r e n t T a s k N u m b e r ( 0 ) , 
         c u r r e n t I s I n t e r r u p t T a s k ( f a l s e ) , 
         c u r r e n t I n t e r r u p t T a s k N u m b e r ( 0 ) , 
         d e s t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e ( f a l s e ) , 
         c u r r e n t R o u t e N u m b e r ( 0 ) , 
         l a s t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         e n t r a n c e W a i t S t a r t T i m e ( I N F I N I T E _ T I M E ) , 
         d i r e c t i o n R a d i a n s ( 0 ) , 
         c u r r e n t B e h a v i o r S t a r t T i m e ( Z E R O _ T I M E ) , 
         l a s t R o u t e C a l c u l a t e d T i m e ( Z E R O _ T I M E ) , 
         l a s t P a t h Q u e r y T r i g g e r T i m e ( Z E R O _ T I M E ) , 
         r e c a l c u l a t e R o u t e ( f a l s e ) , 
         r e c a l c u l a t e R o u t e W i t h B e h a v i o r ( A G E N T _ B E H A V I O R _ A N Y ) , 
         l a s t D e l a y ( Z E R O _ T I M E ) , 
         u t i l i t y 1 C a l c u l a t i o n C o u n t ( 0 ) , 
         u t i l i t y 2 C a l c u l a t i o n C o u n t ( 0 ) , 
         a R a n d o m N u m b e r G e n e r a t o r ( 
                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ,   S E E D _ H A S H I N G ) ) , 
         a R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ( 
                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ,   S E E D _ H A S H I N G _ F O R _ D E S T I N A T I O N _ C H O I C E ) ) , 
         p a r e n t A g e n t I d ( M A S T E R _ A N Y _ A G E N T _ I D ) , 
         v e h i c l e N o d e P t r ( i n i t V e h i c l e N o d e P t r ) , 
         u t i l i t y 1 T r a c e ( 0 . ) , 
         u t i l i t y 2 T r a c e ( 0 . ) , 
         c o n g e s t i o n T r a c e ( 0 . ) , 
         t r a v e l D i s t a n c e T r a c e ( 0 . ) , 
         t r a v e l T i m e T r a c e ( 0 . ) , 
         d e s t i n a t i o n C h a n g e T r a c e ( 0 ) , 
         l a s t T i m e s t e p B e h a v i o r T y p e ( A G E N T _ B E H A V I O R _ N O T H I N G ) 
 { 
         i f   ( i n i t V e h i c l e P t r   ! =   n u l l p t r )   { 
                 c u r r e n t P o s i t i o n I d   =   G i s P o s i t i o n I d T y p e ( G I S _ R O A D ,   i n i t V e h i c l e P t r - > G e t R o a d I d ( ) ) ; 
                 d e s i r e d N e x t P o s i t i o n I d   =   c u r r e n t P o s i t i o n I d ; 
                 l a s t V e r t e x I d   =   i n i t V e h i c l e P t r - > G e t V e r t e x I d ( ) ; 
 
                 c o n s t   V e r t e x   p o s i t i o n   =   t h e A g e n t G i s P t r - > G e t V e r t e x ( l a s t V e r t e x I d ) ; 
 
                 s t a t u s . c u r r e n t P o s i t i o n   =   p o s i t i o n ; 
                 s t a t u s . n e x t P o s i t i o n   =   s t a t u s . c u r r e n t P o s i t i o n ; 
         } 
 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s   = 
                 p r o f i l e P t r - > G e t P a r a m e t e r s ( ) ; 
 
         b o o l   n o t U s e d C a r F l a g ; 
 
         ( * t h i s ) . I n i t i a l i z e S t a t u s W i t h ( p a r a m e t e r s ,   f a l s e / * c a l c u l a t e C a r A n d B i c y c l e P r o b a b i l i t y * / ,   n o t U s e d C a r F l a g ) ; 
 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         m o b i l i t y M o d e l P t r . r e s e t ( n e w   A g e n t M o b i l i t y M o d e l ( r e s o u r c e ) ) ; 
 
         d e s t i n a t i o n C h a n g e T r a c e . U n s e t C h a n g e F l a g ( ) ; 
 } 
 
 
 A g e n t : : A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r ) 
         : 
         s i m u l a t o r P t r ( i n i t S i m u l a t o r P t r ) , 
         a g e n t I d ( i n i t A g e n t I d ) , 
         s i m E n g i n e I n t e r f a c e P t r ( i n i t S i m E n g i n e I n t e r f a c e P t r ) , 
         p r o f i l e P t r ( i n i t P r o f i l e P t r ) , 
         t a s k T a b l e P t r ( i n i t T a s k T a b l e P t r ) , 
         i s D e l e t e d A t T h e E n d O f T i m e S t e p ( f a l s e ) , 
         c u r r e n t T a s k S t a r t T i m e ( Z E R O _ T I M E ) , 
         c u r r e n t T a s k E n d T i m e ( Z E R O _ T I M E ) , 
         i s T a s k I n i t i a l i z e d ( f a l s e ) , 
         c u r r e n t T a s k N u m b e r ( 0 ) , 
         c u r r e n t I s I n t e r r u p t T a s k ( f a l s e ) , 
         c u r r e n t I n t e r r u p t T a s k N u m b e r ( 0 ) , 
         d e s t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e ( f a l s e ) , 
         c u r r e n t R o u t e N u m b e r ( 0 ) , 
         l a s t V e r t e x I d ( I N V A L I D _ V E R T E X _ I D ) , 
         e n t r a n c e W a i t S t a r t T i m e ( I N F I N I T E _ T I M E ) , 
         d i r e c t i o n R a d i a n s ( 0 ) , 
         c u r r e n t B e h a v i o r S t a r t T i m e ( Z E R O _ T I M E ) , 
         l a s t R o u t e C a l c u l a t e d T i m e ( Z E R O _ T I M E ) , 
         l a s t P a t h Q u e r y T r i g g e r T i m e ( Z E R O _ T I M E ) , 
         r e c a l c u l a t e R o u t e ( f a l s e ) , 
         r e c a l c u l a t e R o u t e W i t h B e h a v i o r ( A G E N T _ B E H A V I O R _ A N Y ) , 
         l a s t D e l a y ( Z E R O _ T I M E ) , 
         u t i l i t y 1 C a l c u l a t i o n C o u n t ( 0 ) , 
         u t i l i t y 2 C a l c u l a t i o n C o u n t ( 0 ) , 
         a R a n d o m N u m b e r G e n e r a t o r ( 
                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ,   S E E D _ H A S H I N G ) ) , 
         a R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ( 
                 H a s h I n p u t s T o M a k e S e e d ( i n i t S i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) ,   i n i t A g e n t I d ,   S E E D _ H A S H I N G _ F O R _ D E S T I N A T I O N _ C H O I C E ) ) , 
         p a r e n t A g e n t I d ( M A S T E R _ A N Y _ A G E N T _ I D ) , 
         u t i l i t y 1 T r a c e ( 0 . ) , 
         u t i l i t y 2 T r a c e ( 0 . ) , 
         c o n g e s t i o n T r a c e ( 0 . ) , 
         t r a v e l D i s t a n c e T r a c e ( 0 . ) , 
         t r a v e l T i m e T r a c e ( 0 . ) , 
         d e s t i n a t i o n C h a n g e T r a c e ( 0 ) , 
         l a s t T i m e s t e p B e h a v i o r T y p e ( A G E N T _ B E H A V I O R _ N O T H I N G ) 
 { 
         i f   ( p r o f i l e P t r   ! =   n u l l p t r )   { 
                 A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s   = 
                         p r o f i l e P t r - > G e t P a r a m e t e r s ( ) ; 
 
                 b o o l   n o t U s e d C a r F l a g ; 
 
                 ( * t h i s ) . I n i t i a l i z e S t a t u s W i t h ( p a r a m e t e r s ,   f a l s e / * c a l c u l a t e C a r A n d B i c y c l e P r o b a b i l i t y * / ,   n o t U s e d C a r F l a g ) ; 
 
                 m o b i l i t y M o d e l P t r . r e s e t ( n e w   A g e n t M o b i l i t y M o d e l ( r e s o u r c e ) ) ; 
         } 
 
         d e s t i n a t i o n C h a n g e T r a c e . U n s e t C h a n g e F l a g ( ) ; 
 } 
 
 s h a r e d _ p t r < A g e n t >   A g e n t : : C r e a t e M a s t e r A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r ) 
 { 
         r e t u r n   s h a r e d _ p t r < A g e n t > ( 
                 n e w   A g e n t ( 
                         i n i t S i m u l a t o r P t r , 
                         i n i t A g e n t I d , 
                         s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > ( ) , 
                         i n i t P r o f i l e P t r , 
                         i n i t T a s k T a b l e P t r ) ) ; 
 } 
 
 s h a r e d _ p t r < A g e n t >   A g e n t : : C r e a t e T a x i D r i v e r A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
         c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
         c o n s t   s h a r e d _ p t r < T a x i > &   i n i t T a x i P t r ) 
 { 
         s h a r e d _ p t r < A g e n t >   a g e n t P t r ( 
                 n e w   A g e n t ( 
                         i n i t S i m u l a t o r P t r , 
                         i n i t A g e n t I d , 
                         i n i t S i m E n g i n e I n t e r f a c e P t r , 
                         i n i t P r o f i l e P t r , 
                         i n i t T a s k T a b l e P t r , 
                         i n i t A g e n t G i s P t r , 
                         i n i t P u b l i c V e h i c l e T a b l e P t r , 
                         i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                         i n i t V e h i c l e N o d e P t r , 
                         i n i t T a x i P t r ) ) ; 
 
         a g e n t P t r - > c u r r e n t B e h a v i o r P t r . r e s e t ( 
                 n e w   T a x i D r i v e r B e h a v i o r ( 
                         i n i t A g e n t G i s P t r , 
                         i n i t S i m u l a t o r P t r - > G e t P u b l i c V e h i c l e T a b l e ( ) , 
                         A g e n t R e s o u r c e ( a g e n t P t r ) , 
                         i n i t T a x i P t r , 
                         i n i t S i m u l a t o r P t r - > T i m e S t e p ( )   +   M U L T I A G E N T _ M I N _ T I M E _ S T E P ) ) ; 
 
         r e t u r n   a g e n t P t r ; 
 } 
 
 s h a r e d _ p t r < A g e n t >   A g e n t : : C r e a t e B u s D r i v e r A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
         c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r , 
         c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
         c o n s t   s h a r e d _ p t r < B u s > &   i n i t B u s P t r ) 
 { 
         s h a r e d _ p t r < A g e n t >   a g e n t P t r ( 
                 n e w   A g e n t ( 
                         i n i t S i m u l a t o r P t r , 
                         i n i t A g e n t I d , 
                         i n i t S i m E n g i n e I n t e r f a c e P t r , 
                         i n i t P r o f i l e P t r , 
                         i n i t T a s k T a b l e P t r , 
                         i n i t A g e n t G i s P t r , 
                         i n i t P u b l i c V e h i c l e T a b l e P t r , 
                         i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                         i n i t V e h i c l e N o d e P t r , 
                         i n i t V e h i c l e P t r ) ) ; 
 
         a g e n t P t r - > c u r r e n t B e h a v i o r P t r . r e s e t ( 
                 n e w   B u s D r i v e r B e h a v i o r ( 
                         i n i t A g e n t G i s P t r , 
                         i n i t S i m u l a t o r P t r - > G e t P u b l i c V e h i c l e T a b l e ( ) , 
                         A g e n t R e s o u r c e ( a g e n t P t r ) , 
                         i n i t V e h i c l e P t r , 
                         i n i t B u s P t r , 
                         i n i t S i m u l a t o r P t r - > T i m e S t e p ( )   +   M U L T I A G E N T _ M I N _ T I M E _ S T E P ) ) ; 
 
         a g e n t P t r - > i s T a s k I n i t i a l i z e d   =   t r u e ; 
 
         r e t u r n   a g e n t P t r ; 
 } 
 
 s h a r e d _ p t r < A g e n t >   A g e n t : : C r e a t e T r a i n D r i v e r A g e n t ( 
         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
         c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
         c o n s t   s h a r e d _ p t r < T r a i n > &   i n i t T r a i n P t r ) 
 { 
         s h a r e d _ p t r < A g e n t >   a g e n t P t r ( 
                 n e w   A g e n t ( 
                         i n i t S i m u l a t o r P t r , 
                         i n i t A g e n t I d , 
                         i n i t S i m E n g i n e I n t e r f a c e P t r , 
                         i n i t P r o f i l e P t r , 
                         i n i t T a s k T a b l e P t r , 
                         i n i t A g e n t G i s P t r , 
                         i n i t P u b l i c V e h i c l e T a b l e P t r , 
                         i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                         i n i t V e h i c l e N o d e P t r ) ) ; 
 
         a g e n t P t r - > s t a t u s . c u r r e n t P o s i t i o n   =   i n i t T r a i n P t r - > G e t P o s i t i o n ( ) ; 
         a g e n t P t r - > s t a t u s . n e x t P o s i t i o n   =   a g e n t P t r - > s t a t u s . c u r r e n t P o s i t i o n ; 
 
         a g e n t P t r - > c u r r e n t B e h a v i o r P t r . r e s e t ( 
                 n e w   T r a i n D r i v e r B e h a v i o r ( 
                         i n i t A g e n t G i s P t r , 
                         i n i t S i m u l a t o r P t r - > G e t P u b l i c V e h i c l e T a b l e ( ) , 
                         A g e n t R e s o u r c e ( a g e n t P t r ) , 
                         i n i t T r a i n P t r ) ) ; 
 
         a g e n t P t r - > i s T a s k I n i t i a l i z e d   =   t r u e ; 
 
         r e t u r n   a g e n t P t r ; 
 } 
 
 A g e n t : : ~ A g e n t ( ) 
 { 
         ( * t h i s ) . R e a d y T o D e s t r u c t ( ) ; 
 } 
 
 v o i d   A g e n t : : I n i t i a l i z e S t a t u s W i t h ( 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
         c o n s t   b o o l   c a l c u l a t e C a r A n d B i c y c l e P r o b a b i l i t y , 
         b o o l &   h a s C a r ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         s t a t u s . v a l u e s . r e s i z e ( p a r a m e t e r s . S i z e ( ) ) ; 
 
         m a p < s t r i n g ,   d o u b l e >   a s s i g n e d V a l u e s ; 
 
         c o n s t   b o o l   i s R e s e r v e d M a s t e r A g e n t   = 
                 ( ( a g e n t I d   = =   M A S T E R _ A N Y _ A G E N T _ I D )   | | 
                   ( a g e n t I d   = =   M A S T E R _ B U S _ A G E N T _ I D )   | | 
                   ( a g e n t I d   = =   M A S T E R _ T A X I _ A G E N T _ I D ) ) ; 
 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r   r a n d G e n ( 
                 H a s h I n p u t s T o M a k e S e e d ( 
                         s i m u l a t o r P t r - > G e t M o b i l i t y S e e d ( ) , 
                         a g e n t I d , 
                         S E E D _ H A S H I N G _ F O R _ S C E N A R I O _ G E N E R A T I O N _ S T A T U S _ I N I T ) ) ; 
 
         f o r ( A g e n t S t a t u s I d T y p e   s t a t u s I d   =   0 ;   s t a t u s I d   <   p a r a m e t e r s . S i z e ( ) ;   s t a t u s I d + + )   { 
 
                 i f   ( i s R e s e r v e d M a s t e r A g e n t )   { 
                         i f   ( ! I s B u s O r T a x i P r o f i l e ( s t a t u s I d ) )   { 
                                 c o n t i n u e ; 
                         } 
                 } 
 
                 c o n s t   d o u b l e   v a l u e   =   p a r a m e t e r s [ s t a t u s I d ] . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r a n d G e n ) ; 
 
                 s t a t u s . v a l u e s [ s t a t u s I d ]   =   v a l u e ; 
 
                 a s s i g n e d V a l u e s [ p a r a m e t e r s . G e t L a b e l ( s t a t u s I d ) ]   =   v a l u e ; 
         } 
 
         h a s C a r   =   f a l s e ; 
         h a s B i c y c l e   =   f a l s e ; 
 
         i f   ( c a l c u l a t e C a r A n d B i c y c l e P r o b a b i l i t y )   { 
                 c o n s t   d o u b l e   h a s C a r P e r c e n t a g e   =   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ; 
                 c o n s t   d o u b l e   h a s B i c y c l e P e r c e n t a g e   =   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ; 
 
                 h a s C a r   =   ( p r o f i l e P t r - > G e t H a s C a r R a t i o ( r e s o u r c e ,   r a n d G e n )   > =   h a s C a r P e r c e n t a g e ) ; 
                 ( * t h i s ) . h a s B i c y c l e   =   ( p r o f i l e P t r - > G e t H a s B i c y c l e R a t i o ( r e s o u r c e ,   r a n d G e n )   > =   h a s B i c y c l e P e r c e n t a g e ) ; 
         } 
 
         / /   N o t e :   C a l l   p a r e n t ( S i m u l a t o r )   A P I . 
         / /   R e l a t e d   f u n c t i o n s   o f   S i m u l a t o r   m u s t   b e   i n i t i a l i z e d . 
         s i m u l a t o r P t r - > R e c o r d A s s i g n e d P r o f i l e V a l u e s T o F i l e ( 
                 a g e n t I d , 
                 p r o f i l e P t r , 
                 a s s i g n e d V a l u e s , 
                 h a s C a r , 
                 h a s B i c y c l e ) ; 
 } 
 
 v o i d   A g e n t : : R e a d y T o D e s t r u c t ( ) 
 { 
         / /   C l e a r   b e h a v i o r s . 
         / /   B e h a v i o r s   m a y   r e f e r   a n   a g e n t   p o i n t e r   i n   a n   i n d i r e c t   w a y . 
         c u r r e n t B e h a v i o r P t r . r e s e t ( ) ; 
 
         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : i t e r a t o r   C o m m N o d e I t e r ; 
 
         f o r ( C o m m N o d e I t e r   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > D e t a c h ( ) ; 
         } 
 
         c o m m u n i c a t i o n N o d e P t r s . c l e a r ( ) ; 
 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r   A g e n t I t e r ; 
 
         f o r ( A g e n t I t e r   i t e r   =   c h i l d A g e n t P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c h i l d A g e n t P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > R e a d y T o D e s t r u c t ( ) ; 
         } 
 
         c h i l d A g e n t P t r s . c l e a r ( ) ; 
 } 
 
 S i m T i m e   A g e n t : : C a l c u l a t e W a k e u p T i m e ( ) 
 { 
         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         r e t u r n   t a s k T a b l e P t r - > G e t T a s k ( 0 ) . G e t S t a r t T i m e ( r e s o u r c e ) ; 
 } 
 
 c o n s t   A g e n t T a s k &   A g e n t : : C u r r e n t T a s k ( )   c o n s t 
 { 
         i f   ( t a s k T a b l e P t r - > I s E m p t y ( ) / * f o r   T a x i * / )   { 
                 a s s e r t ( ! c h i l d A g e n t P t r s . e m p t y ( ) ) ; 
 
                 i f   ( ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   & & 
                         ( c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ T A X I _ D R I V E R ) )   { 
 
                         / /   U s e   c h i l d ( c u s t o m e r )   t a s k   i n s t e a d   o f   o w n   t a s k . 
                         r e t u r n   c h i l d A g e n t P t r s . f r o n t ( ) - > C u r r e n t T a s k ( ) ; 
                 } 
         } 
 
         i f   ( c u r r e n t I s I n t e r r u p t T a s k )   { 
                 r e t u r n   t a s k T a b l e P t r - > G e t I n t e r r u p t T a s k ( c u r r e n t I n t e r r u p t T a s k N u m b e r ) ; 
         } 
 
         r e t u r n   t a s k T a b l e P t r - > G e t T a s k ( c u r r e n t T a s k N u m b e r ) ; 
 } 
 
 c o n s t   G i s P o s i t i o n I d T y p e &   A g e n t : : G e t H o m e P o s i t i n I d ( )   c o n s t 
 { 
         i f   ( ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   & & 
                 ( c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ T A X I _ D R I V E R ) )   { 
 
                 / /   U s e   c h i l d ( c u s t o m e r )   r e s o u r c e   i n s t e a d 
                 r e t u r n   A g e n t R e s o u r c e ( c h i l d A g e n t P t r s . f r o n t ( ) . g e t ( ) ) . H o m e P o s i t i o n I d ( ) ; 
         } 
 
         r e t u r n   h o m e P o s i t i o n I d ; 
 } 
 
 b o o l   A g e n t : : S h o u l d C h a n g e R o u t e I n C u r r e n t B e h a v i o r ( c o n s t   A g e n t B e h a v i o r T y p e &   s p e c i f i e d B e h a v i o r )   c o n s t 
 { 
         i f   ( c u r r e n t B e h a v i o r P t r   = =   n u l l p t r )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         c o n s t   A g e n t B e h a v i o r T y p e   c u r r e n t B e h a v i o r T y p e   =   c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( ) ; 
 
         i f   ( c u r r e n t B e h a v i o r P t r - > I s I n t e r n a l R o u t e C h a n e M o d e ( )   & & 
                 n o t A v a i l a b l e B e h a v o r T y p e s F o r N e x t R o u t e C a l c u l a t i o n . f i n d ( c u r r e n t B e h a v i o r T y p e )   = =   n o t A v a i l a b l e B e h a v o r T y p e s F o r N e x t R o u t e C a l c u l a t i o n . e n d ( )   & & 
                 ( s p e c i f i e d B e h a v i o r   = =   A G E N T _ B E H A V I O R _ A N Y   | | 
                   c u r r e n t B e h a v i o r T y p e   = =   s p e c i f i e d B e h a v i o r   | | 
                   c u r r e n t B e h a v i o r T y p e   = =   A G E N T _ B E H A V I O R _ T A X I _ D R I V E R   | | 
                   c u r r e n t B e h a v i o r T y p e   = =   A G E N T _ B E H A V I O R _ B U S _ D R I V E R ) )   { 
                 r e t u r n   t r u e ; 
         } 
 
         r e t u r n   f a l s e ; 
 } 
 
 v o i d   A g e n t : : D e c i d e R o u t e ( c o n s t   A g e n t B e h a v i o r T y p e &   s p e c i f i e d B e h a v i o r ,   b o o l   i s C h a n g e d B y M e e t i n g ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                 c o u t   < <   " L 9 1 5   C h a n g e d B y M e e t i n g   i s   "   < <   i s C h a n g e d B y M e e t i n g   < <   e n d l ; 
         } 
 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s   = 
                 p r o f i l e P t r - > G e t P a r a m e t e r s ( ) ; 
 
         l a s t R o u t e C a l c u l a t e d T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 
         s t a t u s . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ R O U T E _ R E C A L C U L A T I O N _ T I M E ]   = 
                 p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ R O U T E _ R E C A L C U L A T I O N _ T I M E ] . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 
         b o o l   f o u n d R o u t e   =   f a l s e ; 
         b o o l   m u s t N o t R e s e t L a s t s B e h a v i o r ; 
 
         d o   { 
 
                 c o n s t   b o o l   i s I n t e r n a l R o u t e C h a n g e M o d e   =   ( * t h i s ) . S h o u l d C h a n g e R o u t e I n C u r r e n t B e h a v i o r ( s p e c i f i e d B e h a v i o r ) ; 
 
                 b o o l   i s D e s t i n a t i o n C o n t r o l l e d B y B e h a v i o r   =   f a l s e ; 
                 A g e n t B e h a v i o r T y p e   b e h a v i o r T o S e a r c h V e r t e x   =   A G E N T _ B E H A V I O R _ P E D E S T R I A N ; 
                 v e c t o r < V e r t e x I d T y p e >   d e s t V e r t e x I d s ; 
                 v e c t o r < V e r t e x I d T y p e >   s t a r t V e r t e x I d s ; 
 
                 i f   ( i s I n t e r n a l R o u t e C h a n g e M o d e )   { 
                         a s s e r t ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r ) ; 
 
                         b e h a v i o r T o S e a r c h V e r t e x   =   c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( ) ; 
 
                         i s D e s t i n a t i o n C o n t r o l l e d B y B e h a v i o r   = 
                                 c u r r e n t B e h a v i o r P t r - > H a s F i x e d D e s t i n a t i o n V e r t e x ( ) ; 
 
                         m u s t N o t R e s e t L a s t s B e h a v i o r   =   c u r r e n t B e h a v i o r P t r - > I s S t a t i c B e h a v i o r ( ) ; 
                 }   e l s e   { 
                         m u s t N o t R e s e t L a s t s B e h a v i o r   =   f a l s e ; 
                 } 
 
                 i f   ( i s D e s t i n a t i o n C o n t r o l l e d B y B e h a v i o r )   { 
 
                         a s s e r t ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r ) ; 
                         d e s t V e r t e x I d s . p u s h _ b a c k ( c u r r e n t B e h a v i o r P t r - > G e t F i x e d D e s t i n a t i o n V e r t e x I d ( ) ) ; 
 
                 }   e l s e   { 
 
                         i f   ( d e s t P o s i t i o n I d   = =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
 
                                 d e s t V e r t e x I d   =   I N V A L I D _ V E R T E X _ I D ; 
 
                                 / /   C u r r e n t T a s k ( )   w i l l   r e t u r n   n o r m a l   o r   i n t e r r u p t e d   t a s k   d u e   t o   " c u r r e n t I s I n t e r r u p t T a s k "   f l a g . 
                                 c o n s t   A g e n t T a s k &   t a s k   =   ( * t h i s ) . C u r r e n t T a s k ( ) ; 
 
                                 G i s P o s i t i o n I d T y p e   i n i t D e s t P o s i t i o n I d ; 
                                 b o o l   i s M u l t i p l e D e s t i n a t i o n s ; 
 
                                 i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   & &   ( i s C h a n g e d B y M e e t i n g   = =   t r u e ) )   { 
                                 c o u t   < <   " L 9 6 9   I n   "   < <   e n d l ; 
                                 c o u t   < <   " d e s t P o s i t i o n I d   ( "   < <     t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( i n i t D e s t P o s i t i o n I d ) . x   < <   " , "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( i n i t D e s t P o s i t i o n I d ) . y   < <   " ) "   < <   e n d l ; 
                                 } 
 
 
                                 t a s k . G e t D e s t i n a t i o n I d ( 
                                         s i m u l a t o r P t r - > G e t P a r a m e t e r D a t a b a s e R e a d e r ( ) , 
                                         t h e A g e n t G i s P t r , 
                                         ! c u r r e n t I s I n t e r r u p t T a s k / * i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e * / , 
                                         i n i t D e s t P o s i t i o n I d , 
                                         i s M u l t i p l e D e s t i n a t i o n s , 
                                         r e s o u r c e ) ; 
 
                                 i f   ( i n i t D e s t P o s i t i o n I d   = =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
                                         ( * t h i s ) . O u t p u t T r a c e ( " T h e r e   i s   n o   a v a i l a b l e   d e s t i n a t i o n   f o r   c u r r e n t   t a s k . " ) ; 
                                         b r e a k ; 
                                 } 
 
                                 ( * t h i s ) . S e t D e s t i n a t i o n ( 
                                         i n i t D e s t P o s i t i o n I d , 
                                         i s M u l t i p l e D e s t i n a t i o n s , 
                                         f a l s e / * b y C o m m u n i c a t i o n * / ) ; 
 
                                 i f   ( ( d e s t P o s i t i o n I d   = =   d e s i r e d N e x t P o s i t i o n I d )   | | 
                                         ( ( e x t r a D e s t P o i I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D   & & 
                                             e x t r a D e s t P o i I d   = =   d e s i r e d N e x t P o s i t i o n I d ) ) )   { 
                                         b r e a k ; 
                                 } 
 
                                 / /   A s s i g n   p a s s   i n t e r s e c t i o n s   a t   f i r s t   t i m e 
                                 i f   ( t a s k . H a s P a s s V e r t e x S p e c i f i c a t i o n ( ) )   { 
                                         t a s k . G e t P a s s V e r t e x I d s ( 
                                                 s i m u l a t o r P t r - > G e t P a r a m e t e r D a t a b a s e R e a d e r ( ) , 
                                                 t h e A g e n t G i s P t r , 
                                                 s h o u l d P a s s V e r t e x I d s , 
                                                 r e s o u r c e ) ; 
                                 } 
                         } 
 
                           i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   { 
                                 c o u t   < <   " L 1 0 0 8   C u r r e n t B e h a v i o r   I n   "   < <   e n d l ; 
                                 c o u t   < <   " d e s t V e r t e x I d   "   < <   d e s t V e r t e x I d   < <   e n d l ; 
                                 c o u t   < <   " d e s t P o s i t i o n I d   ( "   < <     t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( d e s t P o s i t i o n I d ) . x   < <   " , "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( d e s t P o s i t i o n I d ) . y   < <   " ) "   < <   e n d l ; 
                                 c o u t   < <   " r e s o u r c e P o s i t i o n   ( "   < <   r e s o u r c e . P o s i t i o n ( ) . x   < <   " , "   < <   r e s o u r c e . P o s i t i o n ( ) . y   < <   " ) "   < <   e n d l ; 
                         } 
 
                         / /   r e t u r n   i d s   s o r t e d   b y   d i s t a n c e   f r o m   c u r r e n t   p o s i t i o n . 
 
                         t h e A g e n t G i s P t r - > G e t N e a r R o u t e S e a r c h C a n d i d a t e V e r t e x I d s ( 
                                 r e s o u r c e , 
                                 r e s o u r c e . P o s i t i o n ( ) , 
                                 b e h a v i o r T o S e a r c h V e r t e x , 
                                 d e s t P o s i t i o n I d , 
                                 d e s t V e r t e x I d / * p r i o r i t i z e d D e s t V e r t e x I d   - - >   w i l l   b e   i n s e r t e d   t o   " d e s t V e r t e x I d s "   a s   t h e   f i r s t   e n t r y * / , 
                                 d e s t V e r t e x I d s ) ; 
                 } 
 
                 i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r ) { 
                           i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                                 c o u t   < <   " A A A A A A A A A A A A A A A A A A A A A A A A A A A A A a a "   < <   e n d l ; 
                         
 
                         V e r t e x I d T y p e   t e s t V e r t e x I d   =   c u r r e n t B e h a v i o r P t r - > G e t V i a P o i n t V e r t e x I d ( ) ; 
                         / / V e r t e x   t e s t V e r t   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( t e s t V e r t e x I d ) ; 
 
                         c o u t   < <   " t e s t V e r t   i s   ( "   < <   t e s t V e r t e x I d   < <   " ) "   < <   e n d l ; 
                         } 
                 } 
 
                 i f   ( ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   & &   ( i s C h a n g e d B y M e e t i n g   ! =   t r u e ) )   { 
 
                 / / i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
 
                         / /   s t a r t   n e x t   b e h a v i o r   f r o m   c u r r e n t   b e h a v i o r   v i a   p o i n t 
                         / /   w h e t h e r   t h e   a g e n t   k e e p s   t h e   s a m e   b e h a v i o r   t y p e   o r   n o t . 
                         
 
                         s t a r t V e r t e x I d s . p u s h _ b a c k ( c u r r e n t B e h a v i o r P t r - > G e t V i a P o i n t V e r t e x I d ( ) ) ; 
 
                         i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                                 c o u t   < <   " L 1 0 1 6   C u r r e n t B e h a v i o r   I n   "   < <   e n d l ; 
 
                         V e r t e x I d T y p e   t e s t V e r t e x I d   =   c u r r e n t B e h a v i o r P t r - > G e t V i a P o i n t V e r t e x I d ( ) ; 
                         / / V e r t e x   t e s t V e r t   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( t e s t V e r t e x I d ) ; 
 
                         c o u t   < <   " t e s t V e r t   i s   ( "   < <   t e s t V e r t e x I d   < <   " ) "   < <   e n d l ; 
 
                         } 
 
                 }   e l s e   { 
 
                           i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   { 
                                 c o u t   < <   " L 1 0 2 6   C u r r e n t B e h a v i o r   I n   "   < <   e n d l ; 
                                 c o u t   < <   " l a s t V e r t e x   i s   "   < <   l a s t V e r t e x I d   < <   "   d e s i r e d N e x t   ( "   < <     t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( d e s i r e d N e x t P o s i t i o n I d ) . x   < <   " , "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( d e s i r e d N e x t P o s i t i o n I d ) . y   < <   " ) "   < <   e n d l ; 
                         } 
 
 
                         t h e A g e n t G i s P t r - > G e t N e a r R o u t e S e a r c h C a n d i d a t e V e r t e x I d s ( 
                                 r e s o u r c e , 
                                 t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( d e s t P o s i t i o n I d ) , 
                                 b e h a v i o r T o S e a r c h V e r t e x , 
                                 d e s i r e d N e x t P o s i t i o n I d , 
                                 l a s t V e r t e x I d , 
                                 s t a r t V e r t e x I d s ) ; 
 
                         i f   ( s t a r t V e r t e x I d s . e m p t y ( ) )   { 
                                 i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                                 c o u t   < <   " s t a r t v e r t e x   i s   e m p t y "   < <   e n d l ; 
                                 c o u t   < <   " l a s t v e t t e x   i s   "   < <   l a s t V e r t e x I d   < <   e n d l ; 
                                 } 
                                 s t a r t V e r t e x I d s . p u s h _ b a c k ( l a s t V e r t e x I d ) ; 
                         } 
                 } 
 
                 a s s e r t ( ! s t a r t V e r t e x I d s . e m p t y ( ) ) ; 
 
                 / /   s e a r c h   f r o m   f r o n t ( p r i o r i t i z e d )   v e r t e x 
                 f o r ( s i z e _ t   i   =   0 ;   ( ! f o u n d R o u t e   & &   i   <   d e s t V e r t e x I d s . s i z e ( ) ) ;   i + + )   { 
                         c o n s t   V e r t e x I d T y p e   e n d V e r t e x I d   =   d e s t V e r t e x I d s [ i ] ; 
 
                         f o r ( s i z e _ t   j   =   0 ;   ( ! f o u n d R o u t e   & &   j   <   s t a r t V e r t e x I d s . s i z e ( ) ) ;   j + + )   { 
                                 c o n s t   V e r t e x I d T y p e   s t a r t V e r t e x I d   =   s t a r t V e r t e x I d s [ j ] ; 
 
                                 i f   ( i s I n t e r n a l R o u t e C h a n g e M o d e )   { 
 
                                         o s t r i n g s t r e a m   o u t S t r e a m ; 
                                         o u t S t r e a m   < <   " I n t e r n a l R o u t e C h a n g e   v "   < <   s t a r t V e r t e x I d   < <   "   t o   v "   < <   e n d V e r t e x I d ; 
                                         ( * t h i s ) . O u t p u t T r a c e ( o u t S t r e a m . s t r ( ) ) ; 
 
                                         a s s e r t ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r ) ; 
                                         c u r r e n t B e h a v i o r P t r - > T r y I n t e r n a l R o u t e C h a n g e ( s t a r t V e r t e x I d ,   e n d V e r t e x I d ,   f o u n d R o u t e ) ; 
 
                                 }   e l s e   { 
                                         ( * t h i s ) . D e c i d e R o u t e ( s t a r t V e r t e x I d ,   e n d V e r t e x I d ,   s p e c i f i e d B e h a v i o r ,   f o u n d R o u t e ,   i s C h a n g e d B y M e e t i n g ) ; 
                                 } 
 
                                 i f   ( f o u n d R o u t e )   { 
                                         i f   ( c u r r e n t B e h a v i o r P t r   = =   n u l l p t r )   { 
                                                 l a s t V e r t e x I d   =   s t a r t V e r t e x I d ; 
                                         } 
                                         d e s t V e r t e x I d   =   e n d V e r t e x I d ; 
                                 } 
                         } 
                 } 
 
                 i f   ( ! f o u n d R o u t e / * - - >   n o   r o u t e * /   & & 
                         ! i s D e s t i n a t i o n C o n t r o l l e d B y B e h a v i o r )   { 
 
                         a s s e r t ( d e s t P o s i t i o n I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D ) ; 
 
                         u n r e a c h a b l e D e s t i n a t i o n I d s . i n s e r t ( d e s t P o s i t i o n I d ) ; 
                         i f   ( e x t r a D e s t P o i I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
                                 u n r e a c h a b l e D e s t i n a t i o n I d s . i n s e r t ( e x t r a D e s t P o i I d ) ; 
                         } 
 
                         ( * t h i s ) . O u t p u t T r a c e ( " N o   R o u t e " ) ; 
 
                         i f   ( c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e )   { 
                                 ( * t h i s ) . O u t p u t T r a c e ( " D e s t i n a t i o n   i s   u n r e a c h a b l e .   S e a r c h   o t h e r   d e s t i n a t i o n . " ) ; 
                         } 
 
                         d e s t P o s i t i o n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
 
                         i f   ( n u m b e r N o R o u t e S t a t P t r   ! =   n u l l p t r )   { 
                                 n u m b e r N o R o u t e S t a t P t r - > I n c r e m e n t C o u n t e r ( ) ; 
                         } 
                 } 
 
         }   w h i l e   ( ! f o u n d R o u t e   & &   c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e ) ; 
 
 
         i f   ( d e s t P o s i t i o n I d   = =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
 
                 i f   ( m u s t N o t R e s e t L a s t s B e h a v i o r )   { 
 
                         / /   n o t h i n g   t o   d o 
 
                 }   e l s e   { 
 
                         c u r r e n t R o u t e L i s t . C l e a r ( ) ; 
                         c u r r e n t B e h a v i o r P t r . r e s e t ( ) ; 
                         c u r r e n t R o u t e N u m b e r   =   N O _ R O U T E _ N U M B E R ; 
 
                         t i m e T o S e a r c h R o u t e . S e t M i n T i m e ( r e s o u r c e . C u r r e n t T i m e ( ) ) ; 
                 } 
         } 
 
         ( * t h i s ) . U p d a t e U t i l i t y ( ) ; 
 } 
 
 
 
 v o i d   A g e n t : : D e c i d e R o u t e ( 
         c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
         c o n s t   V e r t e x I d T y p e   e n d V e r t e x I d , 
         c o n s t   A g e n t B e h a v i o r T y p e &   s p e c i f i e d B e h a v i o r , 
         b o o l &   f o u n d R o u t e , 
         b o o l   i s C h a n g e d B y M e e t i n g ) 
 { 
         f o u n d R o u t e   =   f a l s e ; 
 
         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         s h a r e d _ p t r < A g e n t R o u t e >   l a s t R o u t e P t r ; 
 
         i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
                 l a s t R o u t e P t r   =   c u r r e n t R o u t e L i s t . r o u t e P t r s . f r o n t ( ) ; 
         } 
 
         v e c t o r < l i s t < A g e n t R o u t e L i s t >   >   r o u t e C a n d i d a t e s P e r O r d e r ; 
 
         t y p e d e f   l i s t < A g e n t R o u t e L i s t > : : c o n s t _ i t e r a t o r   R o u t e I t e r ; 
 
         v e c t o r < p a i r < R o u t e I t e r ,   d o u b l e >   >   r o u t e I t e r s ; 
         d o u b l e   t o t a l R o u t e W e i g h t   =   0 ; 
         b o o l   h a s B e a v i o r R o u t e   =   f a l s e ; 
 
         i f   ( d e s t P o s i t i o n I d   ! =   d e s i r e d N e x t P o s i t i o n I d   & & 
                 s t a r t V e r t e x I d   ! =   e n d V e r t e x I d )   { 
                 c o n s t   A g e n t T a s k &   t a s k   =   ( * t h i s ) . C u r r e n t T a s k ( ) ; 
 
                 o s t r i n g s t r e a m   o u t S t r e a m ; 
                 o u t S t r e a m   < <   " S e a r c h R o u t e   v "   < <   s t a r t V e r t e x I d   < <   "   t o   v "   < <   e n d V e r t e x I d ; 
                 ( * t h i s ) . O u t p u t T r a c e ( o u t S t r e a m . s t r ( ) ) ; 
 
                 c o n s t   A g e n t B e h a v i o r T y p e   p r e f e r e d B e h a v i o r   =   t a s k . G e t P r e f e r e d B e h a v i o r ( ) ; 
                 A g e n t B e h a v i o r T y p e   b e h a v i o r   =   t a s k . G e t B e h a v i o r ( ) ; 
                 i f   ( s p e c i f i e d B e h a v i o r   ! =   A G E N T _ B E H A V I O R _ A N Y )   { 
                         / /   o v e r w r i t e   b e h a v i o r 
                         b e h a v i o r   =   s p e c i f i e d B e h a v i o r ; 
                 } 
 
                 t h e R o u t e S e a r c h S u b s y s t e m P t r - > S e a r c h R o u t e C a n d i d a t e s ( 
                         r e s o u r c e , 
                         s t a r t V e r t e x I d , 
                         e n d V e r t e x I d , 
                         s h o u l d P a s s V e r t e x I d s , 
                         t i m e T o S e a r c h R o u t e , 
                         p r e f e r e d B e h a v i o r , 
                         n o t A v a i l a b l e B e h a v o r T y p e s F o r N e x t R o u t e C a l c u l a t i o n , 
                         r o u t e C a n d i d a t e s P e r O r d e r ) ; 
 
                 a s s e r t ( ! r o u t e C a n d i d a t e s P e r O r d e r . e m p t y ( ) ) ; 
 
                 i f   ( b e h a v i o r   ! =   A G E N T _ B E H A V I O R _ A N Y )   { 
                         f o r ( s i z e _ t   i   =   0 ;   ( ! h a s B e a v i o r R o u t e   & &   i   <   r o u t e C a n d i d a t e s P e r O r d e r . s i z e ( ) ) ;   i + + )   { 
 
                                 c o n s t   l i s t < A g e n t R o u t e L i s t > &   r o u t e C a n d i d a t e s   =   r o u t e C a n d i d a t e s P e r O r d e r [ i ] ; 
 
                                 f o r ( R o u t e I t e r   i t e r   =   r o u t e C a n d i d a t e s . b e g i n ( ) ; 
                                         ( ! h a s B e a v i o r R o u t e   & &   i t e r   ! =   r o u t e C a n d i d a t e s . e n d ( ) ) ;   i t e r + + )   { 
 
                                         i f   ( ( * i t e r ) . t o t a l C o s t . v a l u e s [ A G E N T _ R O U T E _ C O S T _ M O D E ]   >   0 )   { 
                                                 h a s B e a v i o r R o u t e   =   t r u e ; 
                                         } 
                                 } 
                         } 
                 } 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   r o u t e C a n d i d a t e s P e r O r d e r . s i z e ( ) ;   i + + )   { 
                 c o n s t   l i s t < A g e n t R o u t e L i s t > &   r o u t e C a n d i d a t e s   =   r o u t e C a n d i d a t e s P e r O r d e r [ i ] ; 
 
                 f o r ( R o u t e I t e r   i t e r   =   r o u t e C a n d i d a t e s . b e g i n ( ) ;   i t e r   ! =   r o u t e C a n d i d a t e s . e n d ( ) ;   i t e r + + )   { 
                         c o n s t   A g e n t R o u t e L i s t &   a R o u t e   =   ( * i t e r ) ; 
 
                         i f   ( a R o u t e . I s E m p t y ( ) )   { 
                                 c o n t i n u e ; 
                         } 
                         i f   ( h a s B e a v i o r R o u t e   & &   a R o u t e . t o t a l C o s t . v a l u e s [ A G E N T _ R O U T E _ C O S T _ M O D E ]   < =   0 )   { 
                                 c o n t i n u e ; 
                         } 
 
                         c o n s t   d o u b l e   r o u t e W e i g h t   =   ( * t h i s ) . C a l c u l a t e R o u t e W e i g h t ( a R o u t e ) ; 
 
                         r o u t e I t e r s . p u s h _ b a c k ( m a k e _ p a i r ( i t e r ,   r o u t e W e i g h t ) ) ; 
                         t o t a l R o u t e W e i g h t   + =   r o u t e W e i g h t ; 
 
                         ( * t h i s ) . O u t p u t T r a c e ( 
                                 " R o u t e C a n d i d a t e   "   +   C o n v e r t T o S t r i n g ( r o u t e W e i g h t )   +   " : "   + 
                                 a R o u t e . C o n v e r t T o S t r i n g ( ) ) ; 
                 } 
         } 
 
         i f   ( ( ! r o u t e I t e r s . e m p t y ( ) )   | | 
                 ( s t a r t V e r t e x I d   = =   e n d V e r t e x I d   & &   d e s t P o s i t i o n I d   ! =   d e s i r e d N e x t P o s i t i o n I d )   | | 
                 ( d e s t P o s i t i o n I d   = =   d e s i r e d N e x t P o s i t i o n I d   & & 
                   e x t r a D e s t P o i I d   ! =   e x t r a C u r r e n t P o i I d   & & 
                   e x t r a D e s t P o i I d . I s V a l i d ( ) ) )   { 
 
                 f o u n d R o u t e   =   t r u e ; 
                 c u r r e n t R o u t e N u m b e r + + ; 
 
                 c u r r e n t R o u t e L i s t . C l e a r ( ) ; 
                 t i m e T o S e a r c h R o u t e . S e t M i n T i m e ( r e s o u r c e . C u r r e n t T i m e ( ) ) ; 
 
                 s h a r e d _ p t r < A g e n t R o u t e >   n e x t R o u t e P t r ; 
 
                 i f   ( ! r o u t e I t e r s . e m p t y ( ) )   { 
                         s i z e _ t   r o u t e I d   =   0 ; 
                         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m n u m b e r G e n e r a t o r   =   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
                         i f   ( t o t a l R o u t e W e i g h t   >   0 )   { 
                                 c o n s t   d o u b l e   d e c i d e R a t i o   =   r a n d o m n u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( ) ; 
 
                                 d o u b l e   t o t a l R a t i o   =   0 ; 
 
                                 f o r ( ;   r o u t e I d   <   r o u t e I t e r s . s i z e ( )   -   1 ;   r o u t e I d + + )   { 
                                         t o t a l R a t i o   + =   ( r o u t e I t e r s [ r o u t e I d ] . s e c o n d   /   t o t a l R o u t e W e i g h t ) ; 
 
                                         i f   ( d e c i d e R a t i o   <   t o t a l R a t i o )   { 
                                                 b r e a k ; 
                                         } 
                                 } 
                         }   e l s e   { 
                                 r o u t e I d   =   r a n d o m n u m b e r G e n e r a t o r . G e n e r a t e R a n d o m I n t ( 0 ,   ( i n t 3 2 _ t ) ( r o u t e I t e r s . s i z e ( )   -   1 ) ) ; 
                         } 
                         c u r r e n t R o u t e L i s t   =   * ( r o u t e I t e r s [ r o u t e I d ] . f i r s t ) ; 
 
                         a s s e r t ( ! c u r r e n t R o u t e L i s t . r o u t e P t r s . e m p t y ( ) ) ; 
 
                         i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r   & & 
 
                                 c u r r e n t B e h a v i o r P t r - > I s A c c e p t a b l e R o u t e C h a n g e ( * c u r r e n t R o u t e L i s t . r o u t e P t r s . f r o n t ( ) ) )   { 
                                 c u r r e n t B e h a v i o r P t r - > C h a n g e R o u t e ( c u r r e n t R o u t e L i s t . r o u t e P t r s . f r o n t ( ) ) ; 
 
                         }   e l s e   { 
 
                                 i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
 
                                         i f   ( ! c u r r e n t R o u t e L i s t . r o u t e P t r s . e m p t y ( ) )   { 
                                                 n e x t R o u t e P t r   =   c u r r e n t R o u t e L i s t . r o u t e P t r s . f r o n t ( ) ; 
                                         } 
 
                                         c u r r e n t R o u t e L i s t . r o u t e P t r s . p u s h _ f r o n t ( l a s t R o u t e P t r ) ; 
                                         c u r r e n t B e h a v i o r P t r - > E n d B e h a v i o r A t V i a P o i n t ( n e x t R o u t e P t r ) ; 
 
                                 }   e l s e   { 
                                         i f   ( ! c u r r e n t R o u t e L i s t . I s E m p t y ( ) )   { 
                                                 i f   ( I s F r e e W a l k P o s i t i o n ( d e s i r e d N e x t P o s i t i o n I d . t y p e ) )   { 
                                                         c o n s t   S i m T i m e   p r e p a r e t i o n T i m e   =   3 0 * S E C O N D ; 
 
                                                         c u r r e n t R o u t e L i s t . r o u t e P t r s . p u s h _ f r o n t ( 
                                                                 s h a r e d _ p t r < A g e n t R o u t e > ( n e w   A g e n t R o u t e ( A G E N T _ B E H A V I O R _ F R E E W A L K ) ) ) ; 
 
                                                         c u r r e n t R o u t e L i s t . s t a r t T i m e   - =   p r e p a r e t i o n T i m e ; 
                                                 } 
                                         } 
 
                                         c u r r e n t T a s k S t a r t T i m e   = 
                                                 s t d : : m a x ( c u r r e n t T a s k S t a r t T i m e ,   c u r r e n t R o u t e L i s t . s t a r t T i m e ) ; 
                                 } 
                         } 
                 }   e l s e   { 
                         i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
                                 c u r r e n t R o u t e L i s t . r o u t e P t r s . p u s h _ f r o n t ( l a s t R o u t e P t r ) ; 
                                 c u r r e n t B e h a v i o r P t r - > E n d B e h a v i o r A t V i a P o i n t ( n e x t R o u t e P t r ) ; 
                         } 
                 } 
 
                 i f   ( I s F r e e W a l k P o s i t i o n ( d e s t P o s i t i o n I d . t y p e ) )   { 
                         c u r r e n t R o u t e L i s t . r o u t e P t r s . p u s h _ b a c k ( 
                                 s h a r e d _ p t r < A g e n t R o u t e > ( n e w   A g e n t R o u t e ( A G E N T _ B E H A V I O R _ F R E E W A L K ) ) ) ; 
                 } 
 
                 ( * t h i s ) . O u t p u t T r a c e ( 
                         " R o u t e : "   +   c u r r e n t R o u t e L i s t . C o n v e r t T o S t r i n g ( ) ) ; 
         } 
 } 
 
 d o u b l e   A g e n t : : C a l c u l a t e R o u t e W e i g h t ( c o n s t   A g e n t R o u t e L i s t &   a R o u t e ) 
 { 
         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         c o n s t   d o u b l e   t o t a l W e i g h t   = 
                 p r o f i l e P t r - > C a l c u l a t e R o u t e U t i l i t y ( 
                         r e s o u r c e , 
                         r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) , 
                         A G E N T _ R O U T E _ C O S T _ M O D E , 
                         h e a l t h O r U t i l i t y F a c t o r , 
                         a R o u t e . t o t a l C o s t ) ; 
 
         r e t u r n   s t d : : m a x ( 0 . ,   t o t a l W e i g h t ) ; 
 } 
 
 v o i d   A g e n t : : S e t D e s t i n a t i o n ( 
         c o n s t   G i s P o s i t i o n I d T y p e &   i n i t D e s t P o s i t i o n I d , 
         c o n s t   b o o l   i n i t C a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e , 
         c o n s t   b o o l   b y C o m m u n i c a t i o n ) 
 { 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         G i s P o s i t i o n I d T y p e   n e w D e s t P o s i t i o n I d   =   i n i t D e s t P o s i t i o n I d ; 
         G i s P o s i t i o n I d T y p e   n e w E x t r a D e s t P o i I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
 
         i f   ( n e w D e s t P o s i t i o n I d . t y p e   = =   G I S _ P O I )   { 
                 c o n s t   P o i &   p o i   =   s u b s y s t e m . G e t P o i ( n e w D e s t P o s i t i o n I d . i d ) ; 
 
                 i f   ( p o i . I s A P a r t O f O b j e c t ( ) )   { 
                         n e w D e s t P o s i t i o n I d   =   p o i . G e t P a r e n t G i s P o s i t i o n I d ( ) ; 
 
                         a s s e r t ( n e w D e s t P o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G   | | 
                                       n e w D e s t P o s i t i o n I d . t y p e   = =   G I S _ P A R K ) ; 
 
                         n e w E x t r a D e s t P o i I d   =   i n i t D e s t P o s i t i o n I d ; 
                 } 
         } 
 
         i f   ( d e s t P o s i t i o n I d   ! =   n e w D e s t P o s i t i o n I d   & & 
                 n e w D e s t P o s i t i o n I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
                 d e s t i n a t i o n C h a n g e T r a c e . S e t V a l u e ( * d e s t i n a t i o n C h a n g e T r a c e   +   1 ) ; 
 
                 i f   ( b y C o m m u n i c a t i o n )   { 
                         d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e . S e t V a l u e ( * d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e   +   1 ) ; 
                 } 
 
                 c o n s t   s t r i n g   n a m e   =   s u b s y s t e m . G e t G i s O b j e c t ( i n i t D e s t P o s i t i o n I d ) . G e t O b j e c t N a m e ( ) ; 
 
                 o s t r i n g s t r e a m   o u t S t r e a m ; 
                 o u t S t r e a m   < <   " S e t D e s t i n a t i o n   "   < <   n a m e ; 
 
                 ( * t h i s ) . O u t p u t T r a c e ( o u t S t r e a m . s t r ( ) ) ; 
         } 
 
         s h o u l d P a s s V e r t e x I d s . c l e a r ( ) ; 
         d e s t P o s i t i o n I d   =   n e w D e s t P o s i t i o n I d ; 
         e x t r a D e s t P o i I d   =   n e w E x t r a D e s t P o i I d ; 
 
         c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e   =   i n i t C a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e ; 
         r e c a l c u l a t e R o u t e   =   t r u e ; 
 } 
 
 v o i d   A g e n t : : S e t C u r r e n t D e s t i n a t i o n T o U n r e a c h a b l e P o s i t i o n ( ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         r e s o u r c e . U n r e a c h a b l e D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
 
         l i s t < G i s P o s i t i o n I d T y p e >   u n r e a c h a b l e P o s i t i o n I d s ; 
 
         u n r e a c h a b l e P o s i t i o n I d s . p u s h _ b a c k ( d e s t P o s i t i o n I d ) ; 
 
         i f   ( e x t r a D e s t P o i I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
                 u n r e a c h a b l e P o s i t i o n I d s . p u s h _ b a c k ( e x t r a D e s t P o i I d ) ; 
         } 
 
         ( * t h i s ) . A d d U n r e a c h a b l e P o s i t i o n s ( u n r e a c h a b l e P o s i t i o n I d s ,   f a l s e / * b y C o m m u n i c a t i o n * / ) ; 
 } 
 
 v o i d   A g e n t : : A d d U n r e a c h a b l e P o s i t i o n s ( 
         c o n s t   l i s t < G i s P o s i t i o n I d T y p e > &   u n r e a c h a b l e P o s i t i o n I d s , 
         c o n s t   b o o l   b y C o m m u n i c a t i o n ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         t y p e d e f   l i s t < G i s P o s i t i o n I d T y p e > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   u n r e a c h a b l e P o s i t i o n I d s . b e g i n ( ) ;   i t e r   ! =   u n r e a c h a b l e P o s i t i o n I d s . e n d ( ) ;   i t e r + + )   { 
                 c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d   =   ( * i t e r ) ; 
 
                 / /   a g e n t   i s   i n   a   p o s i t i o n 
                 i f   ( p o s i t i o n I d   = =   d e s i r e d N e x t P o s i t i o n I d   & &   ! r e s o u r c e . W a i t i n g A t E n t r a n c e ( ) )   { 
                         c o n t i n u e ; 
                 } 
 
                 u n r e a c h a b l e D e s t i n a t i o n I d s . i n s e r t ( p o s i t i o n I d ) ; 
         } 
 
         i f   ( u n r e a c h a b l e D e s t i n a t i o n I d s . f i n d ( d e s t P o s i t i o n I d )   ! =   u n r e a c h a b l e D e s t i n a t i o n I d s . e n d ( ) )   { 
 
                 i f   ( ( * t h i s ) . W a i t i n g A t D e s t i n a t i o n E n t r a c e ( ) )   { 
 
                         t h e A g e n t G i s P t r - > P e d e s t r i a n O r D r i v e r G i v e U p E n t r a n c e ( r e s o u r c e ,   d e s t P o s i t i o n I d ) ; 
                 } 
 
                 i f   ( b y C o m m u n i c a t i o n )   { 
                         d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e . S e t V a l u e ( * d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e   +   1 ) ; 
                 } 
                 d e s t P o s i t i o n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
                 r e c a l c u l a t e R o u t e   =   t r u e ; 
         } 
 } 
 
 v o i d   A g e n t : : C h a n g e T o S p e c i f i c D e s t i n a t i o n ( 
         c o n s t   G i s P o s i t i o n I d T y p e &   i n i t D e s t P o s i t i o n I d , 
         c o n s t   V e r t e x I d T y p e &   i n i t D e s t V e r t e x I d , 
         c o n s t   b o o l   b y C o m m u n i c a t i o n ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         i f   ( ( * t h i s ) . W a i t i n g A t D e s t i n a t i o n E n t r a c e ( ) )   { 
                 t h e A g e n t G i s P t r - > P e d e s t r i a n O r D r i v e r G i v e U p E n t r a n c e ( r e s o u r c e ,   d e s i r e d N e x t P o s i t i o n I d ) ; 
         } 
 
         ( * t h i s ) . S e t D e s t i n a t i o n ( i n i t D e s t P o s i t i o n I d ,   f a l s e / * i s M u l t i p l e D e s t i n a t i o n s * / ,   b y C o m m u n i c a t i o n ) ; 
 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 
         c u r r e n t T a s k S t a r t T i m e   =   c u r r e n t T i m e ; 
         d e s t V e r t e x I d   =   i n i t D e s t V e r t e x I d ; 
 
         ( * t h i s ) . R e c a l c u l a t e R o u t e ( c u r r e n t T i m e ) ; 
 } 
 
 v o i d   A g e n t : : M o v e N e x t S t a t e s T o C u r r e n t ( ) 
 { 
         s t a t u s . c u r r e n t P o s i t i o n   =   s t a t u s . n e x t P o s i t i o n ; 
 } 
 
 
 
 v o i d   A g e n t : : I n c r e m e n t T i m e ( ) 
 { 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
         b o o l   c h a n g e d B M   =   f a l s e ; 
 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         ( * t h i s ) . l a s t T i m e s t e p B e h a v i o r T y p e   =   r e s o u r c e . G e t B e h a v i o r T y p e ( ) ; 
 
         i f   ( i s D e l e t e d A t T h e E n d O f T i m e S t e p )   { 
                 r e t u r n ; 
         } 
 
         i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   >   3 5 0 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   <   6 0 0 ) )     { 
         / / c o u t   < <   r e s o u r c e . A g e n t I d ( )   < <   "   :   T i m e S t e p "   < <   e n d l ; 
                 ( * t h i s ) . S e t C h a n g e d B y M e e t i n g ( f a l s e ) ; 
         } 
 
         i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   = =   2 0 0 ) ) { 
                                 c o u t   < <   " T i m e C o u n t e r :   "   < <   C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   < <   e n d l ; 
 
               }   e l s e   i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   >   3 5 0 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   <   6 0 0 ) )   { 
                   c o u t   < <   " T i m e C o u n t e r :   "   < <   C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   < <   e n d l ; 
                   V e r t e x I d T y p e   t e s t V e r t e x I d   =   c u r r e n t B e h a v i o r P t r - > G e t V i a P o i n t V e r t e x I d ( ) ; 
                         / / V e r t e x   t e s t V e r t   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( t e s t V e r t e x I d ) ; 
 
                   c o u t   < <   " I n c r e m e n t   t e s t V e r t   i s   ( "   < <   t e s t V e r t e x I d   < <   " ) "   < <   e n d l ; 
 
                 / /   c h a n g e d B M   =   t r u e ; 
 
                   ( * t h i s ) . S e t C h a n g e d B y M e e t i n g ( f a l s e ) ; 
 
               }   
 
         i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   = =   2 0 0 ) ) { 
                 c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
                 c o n s t   P a r k &   p a r k   =   s u b s y s t e m . G e t P a r k ( d e s t P o s i t i o n I d . i d ) ; 
                 / / A g e n t P a r k &   A p a r k   =   * p a r k P t r s [ d e s t P o s i t i o n I d . i d ] ; 
 
                 c o u t   < <   " D e s t i n a t i o n   i d   i s   "   < <   d e s t P o s i t i o n I d . i d   < <   e n d l ; 
                 c o u t   < <   " D e s t i n a t i o n ' s   c a p a c i t y   i s   "   < <   p a r k . G e t H u m a n C a p a c i t y ( )   < <   e n d l ; 
                 / / c o u t   < <   " D e s t i n a t i o n ' s   c u r r e n t   p e o p l e   i s   "   < <   A p a r k . n u m b e r P e o p l e s   < <   e n d l ; 
                 / / G i s P o s i t i o n I d T y p e &   n e w p a r k   =   s u b s y s t e m . G e t P o s i t i o n ( " p a r k 4 " ,   P a r k & ) ; 
                 c o u t   < <   " U n r e a c h a b l e   n o t i f i c a t i o n "   < <   e n d l ; 
                 ( * t h i s ) . S e t C u r r e n t D e s t i n a t i o n T o U n r e a c h a b l e P o s i t i o n ( ) ; 
 
                 c o u t   < <   " g i v e   y o u   n e w   d e s t i n a t i o n "   < <   e n d l ; 
 
                 ( * t h i s ) . S e t D e s t i n a t i o n ( s u b s y s t e m . G e t P o s i t i o n ( " p a r k 4 " ,   G I S _ P A R K ) ,   f a l s e ,   f a l s e ) ; 
         } 
 
         i f   ( ( A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . D i s t a n c e T o ( A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) )   <   3 . 0 )   & &   ( t r i n i n e   = =   f a l s e ) ) { 
 
                 i f ( r e s o u r c e . A g e n t I d ( )   = =   1 ) { 
                 c o u t   < <   " A g e n t 1   i s   p a r e n t "   < <   e n d l ; 
                 c o u t   < <   " t r i n i n e   i s   "   < <   t r i n i n e   < <   e n d l ; 
                         r e c a l c u l a t e R o u t e   =   t r u e ; 
                         ( * t h i s ) . S e t C h a n g e d B y M e e t i n g ( t r u e ) ; 
                         / / c h a n g e d B M   =   t r u e ; 
                 } 
 
                 
                 i f ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                 c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
                 c o u t   < <   " T w o   A g e n t s   D i s t a n c e   i s   "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . D i s t a n c e T o ( A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) )   < <   e n d l ; 
                 / / r e s o u r c e . S e t D i r e c t i o n R a d i a n s ( 3 . 1 4 ) ; 
                 c h a n g e d B M   =   t r u e ; 
                 t r i n i n e   =   t r u e ; 
                 ( * t h i s ) . S e t C h a n g e d B y M e e t i n g ( t r u e ) ; 
                 ( * t h i s ) . S e t D e s t i n a t i o n ( s u b s y s t e m . G e t P o s i t i o n ( " p a r k 4 " ,   G I S _ P A R K ) ,   f a l s e ,   f a l s e ) ; 
 
                 / / r e c a l c u l a t e R o u t e   =   f a l s e ; 
                 c u r r e n t B e h a v i o r P t r - > C h a n g e R o u t e ( A d d A g e n t s [ 0 ] . C u r r e n t R o u t e L i s t ( ) . r o u t e P t r s . f r o n t ( ) ) ; 
 
 
                 i f   ( ( * t h i s ) . C h a n g e d B y M e e t i n g ) { 
                         c o u t   < <   " S U C C E E E E E D "   < <   e n d l ; 
                 }   e l s e   { 
                         c o u t   < <   " F A L S E E E E E E "   < <   e n d l ; 
                 } 
 
                 } 
 
         } 
 
         / /   i n i t i a l i z a t i o n   ( c a l l e d   o n l y   o n c e   a t   f i r s t   t i m e ) 
         i f   ( ! i s T a s k I n i t i a l i z e d )   { 
                 i s T a s k I n i t i a l i z e d   =   t r u e ; 
                 ( * t h i s ) . A s s i g n C u r r e n t T a s k ( ) ; 
         } 
 
         / / i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 )   { 
         / / c o u t   < <   " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "   < <   e n d l ; 
         / / } 
         / / i f ( c h a n g e d B M   = =   f a l s e ) { 
 
         ( * t h i s ) . M o v e N e x t S t a t e s T o C u r r e n t ( ) ; 
 
           / / } 
 
         c o n s t   G i s P o s i t i o n I d T y p e   l a s t C u r r e n t P o s i t i o n I d   =   c u r r e n t P o s i t i o n I d ; 
         c o n s t   G i s P o s i t i o n I d T y p e   l a s t D e s i r e d N e x t P o s i t i o n I d   =   d e s i r e d N e x t P o s i t i o n I d ; 
 
       / /   i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 9 )   & &   ( c h a n g e d B M   = =   t r u e ) ) { 
         / /         c o u t   < <   " L C P   ( "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( l a s t C u r r e n t P o s i t i o n I d ) . x   < <   " , "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( l a s t C u r r e n t P o s i t i o n I d ) . y   < <   " ) "   < <   e n d l ; 
         / /         c o u t   < <   " L D P   ( "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( l a s t D e s i r e d N e x t P o s i t i o n I d ) . x   < <   " , "   < <   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . G e t P o s i t i o n V e r t e x ( l a s t D e s i r e d N e x t P o s i t i o n I d ) . y   < <   " ) "   < <   e n d l ; 
         / / } 
 
         / /   s t a t u s ( p r o f i l e   v a r i a b l e   o r   t a s k )   c h a n g e s 
         ( * t h i s ) . A p p l y S t a t u s C h a n g e s A n d I n s t a n t i a t e A p p l i c a t i o n s ( ) ; 
 
         / /   r o u t e   ( r e ) c a l c u l a t i o n 
         i f   ( r e s o u r c e . E x c e e d e d R o u t e R e c a l c u l a t i o n T i m e ( ) )   { 
                 r e s o u r c e . R e c a l c u l a t e R o u t e ( ) ; 
         } 
         i f   ( r e c a l c u l a t e R o u t e )   { 
                 i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                 c o u t   < <   " r e s o u r c e   "   < <   r e s o u r c e . A g e n t I d ( )   < <   "   d e c i d e   r o u t e   L 1 4 6 7 ,   c h a n g e d B M   i s   "   < <   c h a n g e d B M   < <   e n d l ; 
                 } 
 
                 ( * t h i s ) . D e c i d e R o u t e ( r e c a l c u l a t e R o u t e W i t h B e h a v i o r ,   c h a n g e d B M ) ; 
 
                 r e c a l c u l a t e R o u t e   =   f a l s e ; 
                 n o t A v a i l a b l e B e h a v o r T y p e s F o r N e x t R o u t e C a l c u l a t i o n . c l e a r ( ) ; 
 
                 i f   ( n u m b e r R o u t e C a l c u l a t e T i m e S t a t P t r   ! =   n u l l p t r )   { 
                         n u m b e r R o u t e C a l c u l a t e T i m e S t a t P t r - > I n c r e m e n t C o u n t e r ( ) ; 
                 } 
 
                 r e c a l c u l a t e R o u t e   =   f a l s e ; 
                 r e c a l c u l a t e R o u t e W i t h B e h a v i o r   =   A G E N T _ B E H A V I O R _ A N Y ; 
         } 
 
 
         i f   ( ( A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . D i s t a n c e T o ( A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) )   <   3 . 0 )   & &   ( t r i n i n e   = =   f a l s e ) ) { 
                 
 
                 i f ( r e s o u r c e . A g e n t I d ( )   = =   1 9 ) { 
                 c o u t   < <   " d o c k   t h e   r o u t e "   < <   e n d l ; 
                 
                 c u r r e n t B e h a v i o r P t r - > C h a n g e R o u t e ( A d d A g e n t s [ 0 ] . C u r r e n t R o u t e L i s t ( ) . r o u t e P t r s . f r o n t ( ) ) ; 
 
 
                 / /   i f   ( ( * t h i s ) . C h a n g e d B y M e e t i n g ) { 
                 / /           c o u t   < <   " S U C C E E E E E D "   < <   e n d l ; 
                 / /   }   e l s e   { 
                 / /           c o u t   < <   " F A L S E E E E E E "   < <   e n d l ; 
                 / /   } 
 
                 } 
 
         } 
 
       
 
           i f   ( ( r e s o u r c e . A g e n t I d ( )   = =   1 )   & &   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   = =   4 0 0 ) ) { 
                 c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
                 c o n s t   P a r k &   p a r k   =   s u b s y s t e m . G e t P a r k ( d e s t P o s i t i o n I d . i d ) ; 
                 / / A g e n t P a r k &   A p a r k   =   * p a r k P t r s [ d e s t P o s i t i o n I d . i d ] ; 
                 c o u t   < <   " D e s t i n a t i o n   i d   i s   "   < <   d e s t P o s i t i o n I d . i d   < <   e n d l ; 
                 c o u t   < <   " D e s t i n a t i o n ' s   c a p a c i t y   i s   "   < <     p a r k . G e t H u m a n C a p a c i t y ( )   < <   e n d l ; 
 
                 c o u t   < <   " A g e n t   p o s i t i o n   ( "   < <   r e s o u r c e . P o s i t i o n ( ) . x   < <   " , "   < <   r e s o u r c e . P o s i t i o n ( ) . y   < <   " ) "   < <   e n d l ; 
                 / / c o u t   < <   " D e s t i n a t i o n ' s   c u r r e n t   p e o p l e   i s   "   < <   A p a r k . n u m b e r P e o p l e s   < <   e n d l ; 
                 / / G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
                 / / G i s P o s i t i o n I d T y p e &   n e w p a r k   =   s u b s y s t e m . G e t P o s i t i o n ( " p a r k 4 " ,   P a r k & ) ; 
                 / / c o u t   < <   " U n r e a c h a b l e   n o t i f i c a t i o n "   < <   e n d l ; 
                 / / ( * t h i s ) . S e t C u r r e n t D e s t i n a t i o n T o U n r e a c h a b l e P o s i t i o n ( ) ; 
 
               / /     c o u t   < <   " A g e n t 1   p o s i t i o n   ( "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . x   < <   " , "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . y   < <   " ) "   < <   e n d l ; 
               / /   c o u t   < <   " A g e n t 1 9   p o s i t i o n   ( "   < <   A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) . x   < <   " , "   < <   A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) . y   < <   " ) "   < <   e n d l ; 
               / /   c o u t   < <   " T h e   D i s t a n c e   i s   "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . D i s t a n c e T o ( A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) )   < <   e n d l ; 
         } 
 
         / /   i f   ( C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   = =   4 0 0 ) { 
         / /       c o u t   < <   " A g e n t 1   p o s i t i o n   ( "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . x   < <   " , "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . y   < <   " ) "   < <   e n d l ; 
         / /       c o u t   < <   " A g e n t 1 9   p o s i t i o n   ( "   < <   A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) . x   < <   " , "   < <   A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) . y   < <   " ) "   < <   e n d l ; 
         / /       c o u t   < <   " T h e   D i s t a n c e   i s   "   < <   A d d A g e n t s [ 0 ] . P o s i t i o n ( ) . D i s t a n c e T o ( A d d A g e n t s [ 1 8 ] . P o s i t i o n ( ) )   < <   e n d l ; 
         / /   } 
 
         / /   e x e c u t e   b e h a v i o r 
         i f   ( c u r r e n t T a s k S t a r t T i m e   < =   c u r r e n t T i m e )   { 
                 b o o l   a s s i g n e d N e w B e h a v i o r ; 
 
                 ( * t h i s ) . R e c a l c u l a t e B e h a v i o r I f N e c e s s a r y ( a s s i g n e d N e w B e h a v i o r ) ; 
 
                 i f   ( a s s i g n e d N e w B e h a v i o r )   { 
                         / / I n c r e m e n t   f r o m   n e x t   t i m e   s t e p . 
                         r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
                 }   e l s e   { 
                         ( * t h i s ) . I n c r e m e n t C u r r e n t B e h a v i o r T i m e ( ) ; 
                 } 
 
         }   e l s e   { 
                 r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
         } 
 
         / /   i f   ( r e s o u r c e . A g e n t I d ( )   = =   1 )   { 
         / / c o u t   < <   " z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z z "   < <   e n d l ; 
         / / } 
 
         / /   n e x t   b e h a v i o r   p r e p a r a t i o n 
         i f   ( ( * t h i s ) . C u r r e n t T a s k H a s F i n i s h e d ( ) )   { 
                 ( * t h i s ) . O u t p u t T r a c e ( " F i n i s h e d   T a s k " ) ; 
 
                 ( * t h i s ) . G o T o N e x t B e h a v i o r I f P o s s i b l e ( ) ; 
 
         / /   G i v e   u p   c u r r e n t   d e s t i n a t i o n   a n d   g o   t o   o t h e r   d e s t i n a t i o n . 
         }   e l s e   i f   ( ( * t h i s ) . O t h e r D e s t i n a t i o n S e e m s T o B e B e t t e r ( ) )   { 
 
                 a s s e r t ( r e s o u r c e . W a i t i n g A t E n t r a n c e ( ) ) ; 
                 a s s e r t ( ( r e s o u r c e . E x c e e d e d W a i t E n t r a n c e T i m e ( ) )   | | 
                               ( r e s o u r c e . E x c e e d e d W a i t V e h i c l e E n t r a n c e T i m e ( ) ) ) ; 
 
                 ( * t h i s ) . O u t p u t T r a c e ( " D e s t i n a t i o n   r e a c h e d   a   l i m i t   c a p a c i t y .   S e t   o t h e r   d e s t i n a t i o n " ) ; 
 
                 ( * t h i s ) . S e t C u r r e n t D e s t i n a t i o n T o U n r e a c h a b l e P o s i t i o n ( ) ; 
         } 
 
         / / a s s e r t ( ( l a s t D e s i r e d N e x t P o s i t i o n I d   = =   d e s i r e d N e x t P o s i t i o n I d )   | | 
         / /               ( c u r r e n t P o s i t i o n I d   = =   l a s t D e s i r e d N e x t P o s i t i o n I d )   | | 
         / /               ( c u r r e n t P o s i t i o n I d   = =   d e s i r e d N e x t P o s i t i o n I d ) ) ; 
 
         / /   u p d a t e   t r a n s l a t i o n   s t a t e 
 
         t h e A g e n t G i s P t r - > U p d a t e P e o p l e T r a n s l a t i o n B e t w e e n G i s O b j e c t s ( 
                 r e s o u r c e , 
                 c u r r e n t P o s i t i o n I d , 
                 l a s t D e s i r e d N e x t P o s i t i o n I d , 
                 d e s i r e d N e x t P o s i t i o n I d , 
                 l a s t T i m e s t e p B e h a v i o r T y p e , 
                 r e s o u r c e . G e t B e h a v i o r T y p e ( ) ) ; 
 
         / /   s t a t i s t i c s / t r a c e s 
         c o n s t   V e r t e x &   c u r r e n t P o s   =   ( * t h i s ) . G e t C u r r e n t P o s i t i o n ( ) ; 
         c o n s t   V e r t e x &   n e x t P o s   =   ( * t h i s ) . G e t N e x t P o s i t i o n ( ) ; 
 
         i f   ( u t i l i t y 1 S t a t P t r   ! =   n u l l p t r )   { 
                 u t i l i t y 1 S t a t P t r - > R e c o r d S t a t V a l u e ( r e s o u r c e . U t i l i t y 1 ( ) ) ; 
         } 
         i f   ( u t i l i t y 2 S t a t P t r   ! =   n u l l p t r )   { 
                 u t i l i t y 2 S t a t P t r - > R e c o r d S t a t V a l u e ( r e s o u r c e . U t i l i t y 2 ( ) ) ; 
         } 
 
         c o n s t   d o u b l e   d i s t a n c e M e t e r s   =   c u r r e n t P o s . D i s t a n c e T o ( n e x t P o s ) ; 
         s t a t u s . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ T O T A L _ T R A V E L _ D I S T A N C E ]   + =   c u r r e n t P o s . D i s t a n c e T o ( n e x t P o s ) ; 
 
         i f   ( d i s t a n c e M e t e r s   > =   M i n S t e p D i s t a n c e T o C o u n t I n S t a t s M e t e r s )   { 
 
                 s t a t u s . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ T O T A L _ T R A V E L _ T I M E ]   + = 
                         d o u b l e ( s i m u l a t o r P t r - > T i m e S t e p ( ) )   /   S E C O N D ; 
 
                 i f   ( t r a v e l D i s t a n c e S t a t P t r   ! =   n u l l p t r )   { 
                         c o n s t   d o u b l e   t r a v e D i s t a n c e   =   r e s o u r c e . T o t a l T r a v e l D i s t a n c e ( ) ; 
                         t r a v e l D i s t a n c e S t a t P t r - > R e c o r d S t a t V a l u e ( t r a v e D i s t a n c e ) ; 
                         t r a v e l D i s t a n c e T r a c e . S e t V a l u e ( t r a v e D i s t a n c e ) ; 
                 } 
                 i f   ( t r a v e l T i m e S t a t P t r   ! =   n u l l p t r )   { 
                         c o n s t   d o u b l e   t r a v e l T i m e   =   r e s o u r c e . T o t a l T r a v e l T i m e ( ) ; 
                         t r a v e l T i m e S t a t P t r - > R e c o r d S t a t V a l u e ( t r a v e l T i m e ) ; 
                         t r a v e l T i m e T r a c e . S e t V a l u e ( t r a v e l T i m e ) ; 
                 } 
         } 
 
         / /   c h l d r e n   c a l c u l a t i o n 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   c h i l d A g e n t P t r s . b e g i n ( ) ;   i t e r   ! =   c h i l d A g e n t P t r s . e n d ( ) ;   i t e r + + )   { 
                 a s s e r t ( a g e n t I d   ! =   ( * i t e r ) - > G e t A g e n t I d ( ) ) ; 
                 ( * i t e r ) - > I n c r e m e n t T i m e ( ) ; 
         } 
 } 
 
 
 
 
 v o i d   A g e n t : : G o T o N e x t B e h a v i o r I f P o s s i b l e ( ) 
 { 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         i f   ( c u r r e n t I s I n t e r r u p t T a s k )   { 
 
                 t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                         A g e n t S t a t u s C h a n g e E v e n t ( 
                                 c u r r e n t T i m e , 
                                 c u r r e n t I n t e r r u p t T a s k N u m b e r , 
                                 A G E N T _ S T A T U S _ C H A N G E _ T A S K _ I N T E R R U P T I O N _ E N D ) ) ; 
 
                 i f   ( ( * t h i s ) . C u r r e n t T a s k ( ) . G e t I n t e r r u p t i o n T y p e ( )   = =   A G E N T _ B E H A V I O R _ I N T E R R U P T I O N _ L A T E R )   { 
                         / /   b a c k   t o   l a s t   ( i n t e r r u p t e d )   n o r m a l   t a s k . 
                         i f   ( c u r r e n t T a s k N u m b e r   >   0 )   { 
                                 c u r r e n t T a s k N u m b e r - - ; 
                         } 
                 } 
 
                 c u r r e n t I s I n t e r r u p t T a s k   =   f a l s e ; 
 
         }   e l s e   { 
                 t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                         A g e n t S t a t u s C h a n g e E v e n t ( 
                                 c u r r e n t T i m e , 
                                 c u r r e n t T a s k N u m b e r , 
                                 A G E N T _ S T A T U S _ C H A N G E _ B A S I C _ T A S K _ E N D ) ) ; 
         } 
 
 
         d o   { 
                 c u r r e n t T a s k N u m b e r + + ; 
 
                 i f   ( ( * t h i s ) . H a s C u r r e n t T a s k ( ) )   { 
                         i f   ( ( * t h i s ) . C u r r e n t T a s k ( ) . S a t i s f y C o n d i t i o n ( r e s o u r c e ) )   { 
                                 ( * t h i s ) . A s s i g n C u r r e n t T a s k ( ) ; 
                                 b r e a k ; 
                         } 
                 } 
 
         }   w h i l e   ( ( * t h i s ) . H a s C u r r e n t T a s k ( ) ) ; 
 
         i f   ( ! ( * t h i s ) . H a s C u r r e n t T a s k ( ) )   { 
                 ( * t h i s ) . O u t p u t T r a c e ( " C o m p l e t e d   A l l   T a s k " ) ; 
                 i s D e l e t e d A t T h e E n d O f T i m e S t e p   =   t r u e ; 
                 d e s i r e d N e x t P o s i t i o n I d   =   G i s P o s i t i o n I d T y p e ( ) ; 
         } 
 } 
 
 v o i d   A g e n t : : A s s i g n C u r r e n t T a s k ( ) 
 { 
         a s s e r t ( ! c u r r e n t I s I n t e r r u p t T a s k ) ; 
 
         c o n s t   A g e n t T a s k &   t a s k   =   ( * t h i s ) . C u r r e n t T a s k ( ) ; 
 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         c u r r e n t T a s k E n d T i m e   =   t a s k . G e t E n d T i m e ( r e s o u r c e ) ; 
         c u r r e n t T a s k S t a r t T i m e   =   t a s k . G e t S t a r t T i m e ( r e s o u r c e ) ; 
 
         c o n s t   S i m T i m e   e a r l y S t a r t T i m e   = 
                 s t d : : m a x ( r e s o u r c e . C u r r e n t T i m e ( ) ,   c u r r e n t T a s k S t a r t T i m e ) ; 
 
         t a s k . G e t T i m e L i n e ( r e s o u r c e ,   e a r l y S t a r t T i m e ,   t i m e T o S e a r c h R o u t e ) ; 
 
         t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                 A g e n t S t a t u s C h a n g e E v e n t ( 
                         e a r l y S t a r t T i m e , 
                         c u r r e n t T a s k N u m b e r , 
                         A G E N T _ S T A T U S _ C H A N G E _ B A S I C _ T A S K _ S T A R T ) ) ; 
 
         d e s t P o s i t i o n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
 
         ( * t h i s ) . R e c a l c u l a t e R o u t e ( s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ) ; 
 } 
 
 v o i d   A g e n t : : A s s i g n I n t e r r u p t T a s k ( ) 
 { 
         a s s e r t ( c u r r e n t I s I n t e r r u p t T a s k ) ; 
 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         i f   ( ( * t h i s ) . W a i t i n g A t D e s t i n a t i o n E n t r a c e ( ) )   { 
                 t h e A g e n t G i s P t r - > P e d e s t r i a n O r D r i v e r G i v e U p E n t r a n c e ( r e s o u r c e ,   d e s i r e d N e x t P o s i t i o n I d ) ; 
         } 
 
         c o n s t   A g e n t T a s k &   t a s k   =   ( * t h i s ) . C u r r e n t T a s k ( ) ; 
 
         c u r r e n t T a s k E n d T i m e   =   t a s k . G e t E n d T i m e ( r e s o u r c e ) ; 
         c u r r e n t T a s k S t a r t T i m e   =   t a s k . G e t S t a r t T i m e ( r e s o u r c e ) ; 
 
         a s s e r t ( c u r r e n t T a s k S t a r t T i m e   = =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ) ; 
 
         t a s k . G e t T i m e L i n e ( r e s o u r c e ,   c u r r e n t T a s k S t a r t T i m e ,   t i m e T o S e a r c h R o u t e ) ; 
 
         d e s t P o s i t i o n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
 
         ( * t h i s ) . R e c a l c u l a t e R o u t e ( s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ) ; 
 } 
 
 v o i d   A g e n t : : A p p l y S t a t u s C h a n g e s A n d I n s t a n t i a t e A p p l i c a t i o n s ( ) 
 { 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 
         w h i l e   ( ! t i m e L i n e S t a t u s C h a n g e E v e n t s . e m p t y ( )   & & 
                       t i m e L i n e S t a t u s C h a n g e E v e n t s . t o p ( ) . t i m e   < =   c u r r e n t T i m e )   { 
 
                 c o n s t   A g e n t S t a t u s C h a n g e E v e n t &   s t a t u s C h a n g e E v e n t   =   t i m e L i n e S t a t u s C h a n g e E v e n t s . t o p ( ) ; 
                 c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
                 c o n s t   A g e n t S t a t u s C h a n g e T y p e &   c h a n g e T y p e   =   s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e T y p e ; 
 
                 i f   ( I s B a s i c T a s k S t a t u s C h a n g e ( c h a n g e T y p e ) )   { 
 
                         i f   ( s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e N u m b e r   <   t a s k T a b l e P t r - > G e t N u m b e r O f T a s k s ( ) )   { 
                                 c o n s t   A g e n t T a s k &   t a s k   =   t a s k T a b l e P t r - > G e t T a s k ( s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e N u m b e r ) ; 
 
                                 i f   ( t a s k . H a s S t a t u s C h a n g e ( c h a n g e T y p e ) )   { 
                                         ( * t h i s ) . A p p l y A d d i t i o n a l S t a t u s C h a n g e s ( t a s k . G e t A d d i t i o n a S t a t u s C h a n g e ( c h a n g e T y p e ) ) ; 
                                 } 
                         } 
 
                 }   e l s e   i f   ( I s I n t e r r u p i o n T a s k S t a t u s C h a n g e ( c h a n g e T y p e ) )   { 
 
                         i f   ( s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e N u m b e r   <   t a s k T a b l e P t r - > G e t N u m b e r O f I n t e r r u p t T a s k s ( ) )   { 
                                 c o n s t   A g e n t T a s k &   t a s k   =   t a s k T a b l e P t r - > G e t I n t e r r u p t T a s k ( s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e N u m b e r ) ; 
 
                                 i f   ( c h a n g e T y p e   = =   A G E N T _ S T A T U S _ C H A N G E _ T A S K _ I N T E R R U P T I O N _ S T A R T )   { 
 
                                         i f   ( t a s k . S a t i s f y C o n d i t i o n ( r e s o u r c e ) )   { 
                                                 ( * t h i s ) . O u t p u t T r a c e ( " I n t e r r u p t C u r r e n t A c t i o n " ) ; 
 
                                                 c u r r e n t I s I n t e r r u p t T a s k   =   t r u e ; 
                                                 c u r r e n t I n t e r r u p t T a s k N u m b e r   =   s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e N u m b e r ; 
 
                                                 i f   ( t a s k . H a s S t a t u s C h a n g e ( c h a n g e T y p e ) )   { 
                                                         ( * t h i s ) . A p p l y A d d i t i o n a l S t a t u s C h a n g e s ( t a s k . G e t A d d i t i o n a S t a t u s C h a n g e ( c h a n g e T y p e ) ) ; 
                                                 } 
 
                                                 ( * t h i s ) . A s s i g n I n t e r r u p t T a s k ( ) ; 
                                         } 
                                 }   e l s e   { 
 
                                         i f   ( t a s k . H a s S t a t u s C h a n g e ( c h a n g e T y p e ) )   { 
                                                 ( * t h i s ) . A p p l y A d d i t i o n a l S t a t u s C h a n g e s ( t a s k . G e t A d d i t i o n a S t a t u s C h a n g e ( c h a n g e T y p e ) ) ; 
                                         } 
                                 } 
                         } 
 
                 }   e l s e   { 
                         a s s e r t ( I s S p e c i f i c T i m e S t a t u s C h a n g e ( c h a n g e T y p e ) ) ; 
 
                         c o n s t   A g e n t T a s k &   t a s k   =   t a s k T a b l e P t r - > G e t S t a t u s C h a n g e ( s t a t u s C h a n g e E v e n t . s t a t u s C h a n g e N u m b e r ) ; 
 
                         i f   ( t a s k . S a t i s f y C o n d i t i o n ( r e s o u r c e ) )   { 
                                 ( * t h i s ) . A p p l y A d d i t i o n a l S t a t u s C h a n g e s ( t a s k . G e t A d d i t i o n a S t a t u s C h a n g e ( c h a n g e T y p e ) ) ; 
                         } 
                 } 
 
                 t i m e L i n e S t a t u s C h a n g e E v e n t s . p o p ( ) ; 
         } 
 } 
 
 v o i d   A g e n t : : A p p l y A d d i t i o n a l S t a t u s C h a n g e s ( c o n s t   A g e n t A d d i t i o n a l S t a t u s C h a n g e &   a d d i t i o n a l S t a t u s C h a n g e ) 
 { 
         ( * t h i s ) . A p p l y S t a t u s C h a n g e s ( a d d i t i o n a l S t a t u s C h a n g e . s t a t u s C h a n g e s ) ; 
         ( * t h i s ) . I n s t a n t i a t e A p p l i c a t i o n s ( a d d i t i o n a l S t a t u s C h a n g e . a p p l i c a t i o n S p e c i f i c a t i o n s ) ; 
 } 
 
 v o i d   A g e n t : : A p p l y S t a t u s C h a n g e s ( c o n s t   v e c t o r < p a i r < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a >   > &   s t a t u s C h a n g e s ) 
 { 
         i f   ( s t a t u s C h a n g e s . e m p t y ( ) )   { 
                 r e t u r n ; 
         } 
 
         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         b o o l   n e e d T o U p d a t e V e h i c l e S t a t u s   =   f a l s e ; 
 
         o s t r i n g s t r e a m   o u t S t r e a m ; 
         o u t S t r e a m   < <   " C h a n g e S t a t u s :   " ; 
 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s   =   p r o f i l e P t r - > G e t P a r a m e t e r s ( ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   s t a t u s C h a n g e s . s i z e ( ) ;   i + + )   { 
                 c o n s t   p a i r < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   s t a t u s C h a n g e   =   s t a t u s C h a n g e s [ i ] ; 
                 c o n s t   A g e n t S t a t u s I d T y p e &   s t a t u s I d   =   s t a t u s C h a n g e . f i r s t ; 
                 c o n s t   A g e n t V a l u e F o r m u l a &   v a l u e F o r m u l a   =   s t a t u s C h a n g e . s e c o n d ; 
 
                 s t a t u s . v a l u e s [ s t a t u s I d ]   =   v a l u e F o r m u l a . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 
                 i f   ( i   >   0 )   { 
                         o u t S t r e a m   < <   " ,   " ; 
                 } 
                 o u t S t r e a m   < <   p a r a m e t e r s . G e t L a b e l ( s t a t u s I d )   < <   "   =   "   < <   s t a t u s . v a l u e s [ s t a t u s I d ] ; 
 
                 i f   ( I s V e h i c l e S t a t u s ( s t a t u s I d ) )   { 
                         n e e d T o U p d a t e V e h i c l e S t a t u s   =   t r u e ; 
                 } 
         } 
 
         ( * t h i s ) . O u t p u t T r a c e ( o u t S t r e a m . s t r ( ) ) ; 
 
         i f   ( n e e d T o U p d a t e V e h i c l e S t a t u s   & &   v e h i c l e P t r   ! =   n u l l p t r )   { 
                 t h e A g e n t G i s P t r - > U p d a t e V e h i c l e S t a t u s ( r e s o u r c e ,   v e h i c l e P t r ) ; 
         } 
 } 
 
 v o i d   A g e n t : : I n s t a n t i a t e A p p l i c a t i o n s ( 
         c o n s t   m a p < D y n a m i c A p p l i c a t i o n I d T y p e ,   D y n a m i c A p p l i c a t i o n D e f i n i t i o n > &   a p p l i c a t i o n S p e c i f i c a t i o n s ) 
 { 
         i f   ( a p p l i c a t i o n S p e c i f i c a t i o n s . e m p t y ( ) )   { 
                 r e t u r n ; 
         } 
 
         t y p e d e f   m a p < D y n a m i c A p p l i c a t i o n I d T y p e ,   D y n a m i c A p p l i c a t i o n D e f i n i t i o n > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
         c o n s t   N o d e I d   t h e N o d e I d   =   a g e n t I d ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 
         f o r ( I t e r T y p e   i t e r   =   a p p l i c a t i o n S p e c i f i c a t i o n s . b e g i n ( ) ; 
                 i t e r   ! =   a p p l i c a t i o n S p e c i f i c a t i o n s . e n d ( ) ;   i t e r + + )   { 
 
                 c o n s t   D y n a m i c A p p l i c a t i o n I d T y p e &   d y n a m i c A p p l i c a t i o n I d   =   ( * i t e r ) . f i r s t ; 
                 c o n s t   D y n a m i c A p p l i c a t i o n D e f i n i t i o n &   a p p l i c a t i o n D e f i n i t i o n   =   ( * i t e r ) . s e c o n d ; 
                 c o n s t   v e c t o r < D y n a m i c A p p l i c a t i o n D e f i n i t i o n P a r a m e t e r > &   p a r a m e t e r s   =   a p p l i c a t i o n D e f i n i t i o n . p a r a m e t e r s ; 
                 c o n s t   s t r i n g &   i n s t a n c e N a m e   =   d y n a m i c A p p l i c a t i o n I d . i n s t a n c e N a m e ; 
 
                 I n t e r f a c e O r I n s t a n c e I d   i n s t a n c e I d ; 
 
                 i f   ( ! i n s t a n c e N a m e . e m p t y ( ) )   { 
                         i n s t a n c e I d   =   i n s t a n c e N a m e   +   " - "   +   C o n v e r t T o S t r i n g ( t h e N o d e I d ) ; 
                 }   e l s e   { 
                         i n s t a n c e I d   =   " d y n a m i c a p p "   +   C o n v e r t T i m e T o S t r i n g S e c s ( c u r r e n t T i m e )   +   " s - "   +   C o n v e r t T o S t r i n g ( t h e N o d e I d ) ; 
                 } 
 
                 o s t r i n g s t r e a m   s c o p e S t r e a m ; 
 
                 s c o p e S t r e a m   < <   " [ "   < <   t h e N o d e I d   < <   " ; "   < <   i n s t a n c e I d   < <   " ] " ; 
 
                 c o n s t   s t r i n g   s c o p e   =   s c o p e S t r e a m . s t r ( ) ; 
 
                 v e c t o r < s t r i n g >   p a r a m e t e r L i n e s ; 
                 s e t < N o d e I d >   t a r g e t N o d e I d s ; 
 
                 t a r g e t N o d e I d s . i n s e r t ( t h e N o d e I d ) ; 
 
                 f o r ( s i z e _ t   i   =   0 ;   i   <   p a r a m e t e r s . s i z e ( ) ;   i + + )   { 
                         c o n s t   D y n a m i c A p p l i c a t i o n D e f i n i t i o n P a r a m e t e r &   p a r a m e t e r   =   p a r a m e t e r s [ i ] ; 
 
                         i f   ( p a r a m e t e r . a p p l i c a t i o n P a r a m e t e r N a m e . f i n d ( " - d e s t i n a t i o n " )   ! =   s t r i n g : : n p o s )   { 
                                 c o n s t   N o d e I d   d e s t i n a t i o n N o d e I d   =   A p p _ C o n v e r t S t r i n g T o N o d e I d O r A n y N o d e I d ( p a r a m e t e r . v a l u e ) ; 
 
                                 t a r g e t N o d e I d s . i n s e r t ( d e s t i n a t i o n N o d e I d ) ; 
                         } 
 
                         c o n s t   s t r i n g &   p a r a m e t e r N a m e   =   p a r a m e t e r . a p p l i c a t i o n P a r a m e t e r N a m e ; 
                         s t r i n g   p a r a m e t e r N a m e W i t h S p a c e   =   p a r a m e t e r . a p p l i c a t i o n P a r a m e t e r N a m e   +   "   " ; 
                         s t r i n g   v a l u e   =   p a r a m e t e r . v a l u e ; 
 
                         / /   S e a r c h   w i t h   w h i t e   s p a c e   e n d   i n d i c a t o r   t o   a v o i d   f i n d i n g   " - s t a r t - t i m e - x x x "   a n d   " - e n d - t i m e - x x x " . 
 
                         i f   ( ( p a r a m e t e r N a m e W i t h S p a c e . f i n d ( " - s t a r t - t i m e   " )   ! =   s t r i n g : : n p o s )   | | 
                                 ( p a r a m e t e r N a m e W i t h S p a c e . f i n d ( " - e n d - t i m e   " )   ! =   s t r i n g : : n p o s ) )   { 
 
                                 S i m T i m e   t i m e V a l u e ; 
                                 b o o l   s u c c e s s ; 
 
                                 C o n v e r t S t r i n g T o T i m e ( v a l u e ,   t i m e V a l u e ,   s u c c e s s ) ; 
 
                                 i f   ( ! s u c c e s s )   { 
                                         c e r r   < <   " E r r o r :   A p p l i c a t i o n   B e h a v i o r ,   b a d   T i m e   p a r a m e t e r   v a l u e   f o r :   "   < <   p a r a m e t e r N a m e ; 
                                         c e r r   < <   "     V a l u e   =   "   < <   v a l u e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 t i m e V a l u e   + =   c u r r e n t T i m e ; 
 
                                 v a l u e   =   C o n v e r t T i m e T o S t r i n g S e c s ( t i m e V a l u e ) ; 
                         } 
 
                         c o n s t   s t r i n g   p a r a m e t e r L i n e   =   s c o p e   +   "   "   +   p a r a m e t e r N a m e   +   "   =   "   +   v a l u e ; 
 
                         p a r a m e t e r L i n e s . p u s h _ b a c k ( p a r a m e t e r L i n e ) ; 
 
                 } 
 
                 o s t r i n g s t r e a m   o u t S t r e a m ; 
                 o u t S t r e a m   < <   " G e n e r a t e A p p l i c a t i o n :   " ; 
 
                 f o r ( s i z e _ t   i   =   0 ;   i   <   p a r a m e t e r L i n e s . s i z e ( ) ;   i + + )   { 
                         i f   ( i   >   0 )   { 
                                 o u t S t r e a m   < <   " ,   " ; 
                         } 
                         o u t S t r e a m   < <   p a r a m e t e r L i n e s [ i ] ; 
                 } 
 
                 ( * t h i s ) . O u t p u t T r a c e ( o u t S t r e a m . s t r ( ) ) ; 
 
                 s i m u l a t o r P t r - > C r e a t e A p p l i c a t i o n F o r N o d e ( 
                         r e s o u r c e , 
                         t h e N o d e I d , 
                         i n s t a n c e I d , 
                         p a r a m e t e r L i n e s , 
                         t a r g e t N o d e I d s ) ; 
         } 
 } 
 
 v o i d   A g e n t : : R e c a l c u l a t e B e h a v i o r I f N e c e s s a r y ( b o o l &   a s s i g n e d N e w B e h a v i o r ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r   | |   r e s o u r c e . W a i t i n g A t E n t r a n c e ( ) )   { 
                 a s s i g n e d N e w B e h a v i o r   =   f a l s e ; 
                 r e t u r n ; 
         } 
 
         i f   ( c u r r e n t R o u t e L i s t . I s E m p t y ( ) )   { 
                 a s s i g n e d N e w B e h a v i o r   =   f a l s e ; 
                 r e t u r n ; 
         } 
 
         a s s i g n e d N e w B e h a v i o r   =   t r u e ; 
 
         ( * t h i s ) . O u t p u t T r a c e ( " A s s i g n   B e h a v i o r   f o r   "   +   c u r r e n t R o u t e L i s t . C o n v e r t T o S t r i n g ( ) ) ; 
 
         c o n s t   s h a r e d _ p t r < A g e n t R o u t e >   r o u t e P t r   =   c u r r e n t R o u t e L i s t . r o u t e P t r s . f r o n t ( ) ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
 
         c u r r e n t B e h a v i o r S t a r t T i m e   =   c u r r e n t T i m e ; 
         c u r r e n t B e h a v i o r C o s t   =   A g e n t R o u t e C o s t ( ) ; 
 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e >   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r   =   s i m u l a t o r P t r - > G e t P u b l i c V e h i c l e T a b l e ( ) ; 
 
         s w i t c h   ( r o u t e P t r - > b e h a v i o r )   { 
         c a s e   A G E N T _ B E H A V I O R _ F R E E W A L K :   { 
 
                 G i s P o s i t i o n I d T y p e   e n d P o s i t i o n I d   =   d e s t P o s i t i o n I d ; 
                 b o o l   e n t e r T o P o s i t i o n ; 
 
                 i f   ( c u r r e n t R o u t e L i s t . r o u t e P t r s . s i z e ( )   >   1 )   { 
                         e n t e r T o P o s i t i o n   =   f a l s e ; / /   - >   l e a v e   f r o m   p o s i t i o n 
 
                         l i s t < s h a r e d _ p t r < A g e n t R o u t e >   > : : c o n s t _ i t e r a t o r   i t e r   = 
                                 c u r r e n t R o u t e L i s t . r o u t e P t r s . b e g i n ( ) ; 
 
                         i t e r + + ; 
 
                         i f   ( ( * i t e r ) - > I s R o a d ( ) )   { 
                                 e n d P o s i t i o n I d   =   ( * i t e r ) - > G e t S t a r t R o a d P o s i t i o n I d ( ) ; 
                         }   e l s e   { 
                                 e n d P o s i t i o n I d   =   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r - > G e t P o s i t i o n I d ( ( * i t e r ) - > G e t S t a r t S t o p I d ( ) ) ; 
                         } 
 
                 }   e l s e   { 
                         e n t e r T o P o s i t i o n   =   t r u e ; 
 
                         a s s e r t ( e n d P o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G   | | 
                                       e n d P o s i t i o n I d . t y p e   = =   G I S _ P A R K   | | 
                                       e n d P o s i t i o n I d . t y p e   = =   G I S _ P O I ) ; 
 
                         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( e n d P o s i t i o n I d ) ; 
                 } 
 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( 
                         n e w   F r e e W a l k B e h a v i o r ( t h e A g e n t G i s P t r ,   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r ,   r o u t e P t r ,   e n d P o s i t i o n I d ,   e n t e r T o P o s i t i o n ,   r e s o u r c e ) ) ; 
                 b r e a k ; 
         } 
 
         c a s e   A G E N T _ B E H A V I O R _ V E H I C L E : 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( 
                         n e w   V e h i c l e D r i v e r B e h a v i o r ( 
                                 t h e A g e n t G i s P t r ,   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r ,   r o u t e P t r ,   r e s o u r c e ,   v e h i c l e P t r ,   s i m u l a t o r P t r - > T i m e S t e p ( )   +   M U L T I A G E N T _ M I N _ T I M E _ S T E P ) ) ; 
                 b r e a k ; 
 
         c a s e   A G E N T _ B E H A V I O R _ B U S : 
         c a s e   A G E N T _ B E H A V I O R _ T R A I N : 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( 
                         n e w   P u b l i c V e h i c l e B e h a v i o r ( 
                                 t h e A g e n t G i s P t r ,   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r ,   r o u t e P t r ,   r e s o u r c e ) ) ; 
                 b r e a k ; 
 
         c a s e   A G E N T _ B E H A V I O R _ T A X I : 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( 
                         n e w   T a x i G u e s t B e h a v i o r ( t h e A g e n t G i s P t r ,   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r ,   r o u t e P t r ,   r e s o u r c e ) ) ; 
                 b r e a k ; 
 
         c a s e   A G E N T _ B E H A V I O R _ B I C Y C L E : 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( 
                         n e w   B i c y c l e B e h a v i o r ( t h e A g e n t G i s P t r ,   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r ,   r o u t e P t r ,   r e s o u r c e ) ) ; 
                 b r e a k ; 
 
         c a s e   A G E N T _ B E H A V I O R _ P E D E S T R I A N : 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( 
                         n e w   P e d e s t r i a n B e h a v i o r ( t h e A g e n t G i s P t r ,   t h e P u b l i c V e h i c l e T a b l e C o n s t P t r ,   r o u t e P t r ,   r e s o u r c e ) ) ; 
                 b r e a k ; 
         d e f a u l t : 
                 a s s e r t ( f a l s e ) ;   a b o r t ( ) ;   b r e a k ; 
         } 
 
         i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
                 ( * t h i s ) . O u t p u t T r a c e ( " N e w   B e h a v i o r : "   +   c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r N a m e ( ) ) ; 
         } 
 
         ( * t h i s ) . U p d a t e U t i l i t y ( ) ; 
 } 
 
 v o i d   A g e n t : : I n c r e m e n t C u r r e n t B e h a v i o r T i m e ( ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         i f   ( c u r r e n t B e h a v i o r P t r   = =   n u l l p t r   | |   r e s o u r c e . W a i t i n g A t E n t r a n c e ( ) )   { 
                 r e s o u r c e . S e t P o s i t i o n ( r e s o u r c e . P o s i t i o n ( ) ) ; 
                 r e t u r n ; 
         } 
 
         c u r r e n t B e h a v i o r P t r - > I n c r e m e n t T i m e S t e p ( s i m u l a t o r P t r - > T i m e S t e p ( ) ) ; 
 
         i f   ( M u l t i A g e n t S i m u l a t o r : : i s D e b u g M o d e )   { 
                 ( * t h i s ) . O u t p u t T r a c e ( c u r r e n t B e h a v i o r P t r - > M a k e P o s i t i o n T r a c e S t r i n g ( ) ) ; 
         } / / i f / / 
 
         i f   ( ! r e c a l c u l a t e R o u t e   & &   c u r r e n t B e h a v i o r P t r - > H a s F i n i s h e d ( ) )   { 
 
                 l a s t D e l a y   =   r e s o u r c e . N e x t D e l a y ( ) ; 
                 ( * t h i s ) . U p d a t e U t i l i t y ( ) ; 
 
                 c u r r e n t B e h a v i o r P t r . r e s e t ( ) ; 
 
                 ( * t h i s ) . O u t p u t T r a c e ( " E n d   B e h a v i o r " ) ; 
 
                 i f   ( ! c u r r e n t R o u t e L i s t . I s E m p t y ( ) )   { 
 
                         c u r r e n t R o u t e L i s t . r o u t e P t r s . p o p _ f r o n t ( ) ; 
                 } 
 
                 i f   ( c u r r e n t R o u t e L i s t . r o u t e P t r s . e m p t y ( )   & &   ( * t h i s ) . H a s C u r r e n t T a s k ( ) )   { 
                         c o n s t   S i m T i m e   c u r r e n t T i m e   =   r e s o u r c e . C u r r e n t T i m e ( ) ; 
                         c o n s t   S i m T i m e   w a i t T i m e   =   ( * t h i s ) . C u r r e n t T a s k ( ) . G e t W a i t T i m e ( r e s o u r c e ) ; 
                         c o n s t   S i m T i m e   w a i t E n d T i m e   =   c u r r e n t T i m e   +   w a i t T i m e ; 
 
                         i f   ( w a i t T i m e   >   Z E R O _ T I M E )   { 
                                 i f   ( c u r r e n t I s I n t e r r u p t T a s k )   { 
                                         t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                                                 A g e n t S t a t u s C h a n g e E v e n t ( 
                                                         c u r r e n t T i m e , 
                                                         c u r r e n t I n t e r r u p t T a s k N u m b e r , 
                                                         A G E N T _ S T A T U S _ C H A N G E _ T A S K _ I N T E R R U P T I O N _ B E F O R E _ W A I T I N G ) ) ; 
                                 }   e l s e   { 
                                         t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                                                 A g e n t S t a t u s C h a n g e E v e n t ( 
                                                         c u r r e n t T i m e , 
                                                         c u r r e n t T a s k N u m b e r , 
                                                         A G E N T _ S T A T U S _ C H A N G E _ B A S I C _ T A S K _ B E F O R E _ W A I T I N G ) ) ; 
                                 } 
                         } 
 
                         i f   ( c u r r e n t T a s k E n d T i m e   <   I N F I N I T E _ T I M E )   { 
                                 c u r r e n t T a s k E n d T i m e   =   s t d : : m a x ( c u r r e n t T a s k E n d T i m e ,   w a i t E n d T i m e ) ; 
                         }   e l s e   { 
                                 c u r r e n t T a s k E n d T i m e   =   w a i t E n d T i m e ; 
                         } 
                 } 
         } 
 
         / / ( * t h i s ) . U p d a t e H e a l t h F a c t o r ( ) ; 
 } 
 
 v o i d   A g e n t : : U p d a t e H e a l t h F a c t o r ( ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ U T I L I T Y _ F A C T O R _ L A S T _ D E L A Y ]   =   d o u b l e ( r e s o u r c e . L a s t D e l a y ( ) )   /   S E C O N D ; 
         h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ U T I L I T Y _ F A C T O R _ N E X T _ D E L A Y ]   =   d o u b l e ( r e s o u r c e . N e x t D e l a y ( ) )   /   S E C O N D ; 
         h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ U T I L I T Y _ F A C T O R _ T R I P _ D E L A Y ]   =   d o u b l e ( r e s o u r c e . T r i p D e l a y ( ) )   /   S E C O N D ; 
         h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ U T I L I T Y _ F A C T O R _ A R R I V A L _ D E L A Y ]   =   d o u b l e ( r e s o u r c e . A r r i v a l D e l a y ( ) )   /   S E C O N D ; 
 } 
 
 v o i d   A g e n t : : U p d a t e U t i l i t y ( ) 
 { 
         ( * t h i s ) . U p d a t e H e a l t h F a c t o r ( ) ; 
 
         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
         u t i l i t y 1 C a l c u l a t i o n C o u n t + + ; 
         u t i l i t y 2 C a l c u l a t i o n C o u n t + + ; 
 
         s t a t u s . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ U T I L I T Y 1 ]   = 
                 p r o f i l e P t r - > C a l c u l a t e U t i l i t y 1 ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ,   h e a l t h O r U t i l i t y F a c t o r ,   c u r r e n t R o u t e L i s t . t o t a l C o s t ) ; 
         s t a t u s . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ U T I L I T Y 2 ]   = 
                 p r o f i l e P t r - > C a l c u l a t e U t i l i t y 2 ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ,   h e a l t h O r U t i l i t y F a c t o r ,   c u r r e n t R o u t e L i s t . t o t a l C o s t ) ; 
         h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ U T I L I T Y _ F A C T O R _ U T I L I T Y 1 _ C O U N T E R ]   =   u t i l i t y 1 C a l c u l a t i o n C o u n t ; 
         h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ U T I L I T Y _ F A C T O R _ U T I L I T Y 2 _ C O U N T E R ]   =   u t i l i t y 2 C a l c u l a t i o n C o u n t ; 
 
         c o n s t   d o u b l e   u t i l i t y 1   =   r e s o u r c e . U t i l i t y 1 ( ) ; 
         c o n s t   d o u b l e   u t i l i t y 2   =   r e s o u r c e . U t i l i t y 2 ( ) ; 
 
         u t i l i t y 1 T r a c e . S e t V a l u e ( u t i l i t y 1 ) ; 
         u t i l i t y 2 T r a c e . S e t V a l u e ( u t i l i t y 2 ) ; 
 
         ( * t h i s ) . O u t p u t T r a c e ( " U t i l i t y   =   "   +   C o n v e r t T o S t r i n g ( u t i l i t y 1 )   +   "   /   "   +     C o n v e r t T o S t r i n g ( u t i l i t y 2 ) ) ; 
 } 
 
 b o o l   A g e n t : : C u r r e n t T a s k H a s F i n i s h e d ( )   c o n s t 
 { 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 
         i f   ( c u r r e n t T i m e   <   c u r r e n t T a s k S t a r t T i m e )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         i f   ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         i f   ( ! c u r r e n t R o u t e L i s t . I s E m p t y ( ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         / /   1 .   D y n a m i c a l l y   g e n e r a t e d   a g e n t s   i n   g i s   o b j e c t   w h i c h   h a s   c a p a c i t y   m a y   w a i t   e n t r a n c e . 
         / /   2 .   A g e n t s   a r e   g o i n g   t o   s k i p   c u r r e n t   t a s k   i f   t h e r e   i s   n o   r o u t e   a n d   t r y   t o   l e a v e ( ; b e   d e l e t e d )   f r o m   s i m u l a t i o n   a t   t h e   e n d   o f   t h e   l a s t   t a s k . 
         / /   G u a r a n t e e   t h e   a g e n t   e n t r a n c e   b e f o r e   t h e   a g e n t   d e l e t i o n . 
 
         i f   ( ( * t h i s ) . W a i t i n g A t E n t r a n c e ( ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         i f   ( c u r r e n t T a s k E n d T i m e   <   I N F I N I T E _ T I M E )   { 
                 r e t u r n   ( c u r r e n t T i m e   > =   c u r r e n t T a s k E n d T i m e ) ; 
         } 
 
         r e t u r n   t r u e ; 
 } 
 
 b o o l   A g e n t : : H a s C u r r e n t T a s k ( )   c o n s t 
 { 
         r e t u r n   ( c u r r e n t T a s k N u m b e r   <   t a s k T a b l e P t r - > G e t N u m b e r O f T a s k s ( ) ) ; 
 } 
 
 v o i d   A g e n t : : A d d C o m m u n i c a t i o n N o d e ( c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) 
 { 
         c o m m u n i c a t i o n N o d e P t r - > r e s o u r c e   =   A g e n t R e s o u r c e ( t h i s ) ;   / / c o n n e c t   r e s o u r c e 
 
         c o m m u n i c a t i o n N o d e P t r s . i n s e r t ( c o m m u n i c a t i o n N o d e P t r ) ; 
 
         c o m m u n i c a t i o n N o d e P t r - > A t t a c h ( m o b i l i t y M o d e l P t r ) ; 
 } 
 
 v o i d   A g e n t : : D e l e t e C o m m u n i c a t i o n N o d e ( c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) 
 { 
         a s s e r t ( c o m m u n i c a t i o n N o d e P t r s . f i n d ( c o m m u n i c a t i o n N o d e P t r )   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ) ; 
 
         c o m m u n i c a t i o n N o d e P t r s . e r a s e ( c o m m u n i c a t i o n N o d e P t r ) ; 
 
         c o m m u n i c a t i o n N o d e P t r - > D e t a c h ( ) ; 
 } 
 
 v o i d   A g e n t : : R e c a l c u l a t e R o u t e ( 
         c o n s t   S i m T i m e &   r e c a l c u l a t e S t a r t T i m e , 
         c o n s t   A g e n t B e h a v i o r T y p e &   i n i t R e c a l c u l a t e R o u t e W i t h B e h a v i o r ) 
 { 
         t i m e T o S e a r c h R o u t e . S e t M i n T i m e ( r e c a l c u l a t e S t a r t T i m e ) ; 
 
         r e c a l c u l a t e R o u t e   =   t r u e ; 
         r e c a l c u l a t e R o u t e W i t h B e h a v i o r   =   i n i t R e c a l c u l a t e R o u t e W i t h B e h a v i o r ; 
 } 
 
 v o i d   A g e n t : : S e t C h a n g e d B y M e e t i n g ( b o o l   i n p u t ) 
 { 
         C h a n g e d B y M e e t i n g   =   i n p u t ; 
 } 
 
 v o i d   A g e n t : : S e t V e r t e x I d ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) 
 { 
         i f   ( l a s t V e r t e x I d   ! =   v e r t e x I d )   { 
 
                 i f   ( ! s h o u l d P a s s V e r t e x I d s . e m p t y ( ) )   { 
                         i f   ( s h o u l d P a s s V e r t e x I d s . f r o n t ( )   = =   v e r t e x I d )   { 
                                 s h o u l d P a s s V e r t e x I d s . p o p _ f r o n t ( ) ; 
                         } 
                 } 
 
                 i f   ( ! c o m m u n i c a t i o n N o d e P t r s . e m p t y ( ) )   { 
                         c o n s t   V e r t e x   p o s i t i o n   =   t h e A g e n t G i s P t r - > G e t V e r t e x ( v e r t e x I d ) ; 
 
                         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
                         f o r ( I t e r T y p e   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
                                 ( * i t e r ) - > A r r i v e d A t V e r t e x N o t i f i c a t i o n ( v e r t e x I d ,   p o s i t i o n ) ; 
                         } 
                 } 
         } 
 
         l a s t V e r t e x I d   =   v e r t e x I d ; 
 } 
 
 b o o l   A g e n t : : W a i t i n g A t D e s t i n a t i o n E n t r a c e ( )   c o n s t 
 { 
         i f   ( ! ( * t h i s ) . W a i t i n g A t E n t r a n c e ( ) )   { 
                 r e t u r n   f a l s e ; 
         } / / i f / / 
 
         / /   I n   v e h i c l e   b e h a v i o r ,   e n t r a n c e   w a i t   o c c u r s 
         / /   o n l y   a t   t h e   d e s t i a n t i o n   p o s i t i o n . 
 
         r e t u r n   ( ( / * j a y * / d e s i r e d N e x t P o s i t i o n I d   = =   d e s t P o s i t i o n I d )   | | 
 
                         ( ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   & & 
                           ( c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ V E H I C L E ) ) ) ; 
 } 
 
 b o o l   A g e n t : : W a i t i n g A t E n t r a n c e ( )   c o n s t 
 { 
         r e t u r n   ( e n t r a n c e W a i t S t a r t T i m e   ! =   I N F I N I T E _ T I M E ) ; 
 } 
 
 b o o l   A g e n t : : O t h e r D e s t i n a t i o n S e e m s T o B e B e t t e r ( ) 
 { 
         i f   ( ! c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         i f   ( ( * t h i s ) . W a i t i n g A t D e s t i n a t i o n E n t r a c e ( ) )   { 
 
                 c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( t h i s ) ; 
 
                 i f   ( ( c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   & & 
                         ( c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ V E H I C L E ) )   { 
 
                         i f   ( r e s o u r c e . E x c e e d e d W a i t V e h i c l e E n t r a n c e T i m e ( ) )   { 
                                 r e t u r n   t r u e ; 
                         } / / i f / / 
                 } 
                 e l s e   { 
 
                         i f   ( r e s o u r c e . E x c e e d e d W a i t E n t r a n c e T i m e ( ) )   { 
                                 r e t u r n   t r u e ; 
                         } 
                 } 
         } 
 
         r e t u r n   f a l s e ; 
 } 
 
 c o n s t   V e r t e x &   A g e n t : : G e t C u r r e n t P o s i t i o n ( )   c o n s t 
 { 
         r e t u r n   ( s t a t u s . c u r r e n t P o s i t i o n ) ; 
 } 
 
 c o n s t   V e r t e x &   A g e n t : : G e t N e x t P o s i t i o n ( )   c o n s t 
 { 
         r e t u r n   ( s t a t u s . n e x t P o s i t i o n ) ; 
 } 
 
 A g e n t P r o f i l e T y p e   A g e n t R e s o u r c e : : P r o f i l e T y p e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > p r o f i l e P t r - > G e t P r o f i l e T y p e ( ) ; 
 } 
 
 S i m T i m e   A g e n t R e s o u r c e : : C u r r e n t T i m e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
 } 
 
 S i m T i m e   A g e n t R e s o u r c e : : C u r r e n t B e h a v i o r S p e n t T i m e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   ( ( * t h i s ) . C u r r e n t T i m e ( )   -   a g e n t P t r - > c u r r e n t B e h a v i o r S t a r t T i m e ) ; 
 } 
 
 A g e n t M o b i l i t y C l a s s T y p e   A g e n t R e s o u r c e : : M o b i l i t y C l a s s ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > p r o f i l e P t r - > G e t M o b i l i t y C l a s s ( ) ; 
 } 
 
 A g e n t T i c k e t T y p e   A g e n t R e s o u r c e : : T i c k e t T y p e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > p r o f i l e P t r - > G e t T i c k e t T y p e ( ) ; 
 } 
 
 A g e n t U s e r T y p e   A g e n t R e s o u r c e : : U s e r T y p e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > p r o f i l e P t r - > G e t U s e r T y p e ( ) ; 
 } 
 
 c o n s t   V e r t e x &   A g e n t R e s o u r c e : : P o s i t i o n ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > G e t C u r r e n t P o s i t i o n ( ) ; 
 } 
 
 s t r i n g   A g e n t R e s o u r c e : : G e t P r o f i l e N a m e ( )   c o n s t 
 { 
         i f   ( a g e n t P t r   = =   n u l l p t r )   { 
                 r e t u r n   s t r i n g ( ) ; 
         } 
 
         r e t u r n   a g e n t P t r - > p r o f i l e P t r - > G e t P r o f i l e N a m e ( ) ; 
 } 
 
 c o n s t   V e r t e x &   A g e n t R e s o u r c e : : D e b u g N e x t P o s i t i o n ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > G e t N e x t P o s i t i o n ( ) ; 
 } 
 
 O b j e c t M o b i l i t y P o s i t i o n   A g e n t R e s o u r c e : : M o b i l i t y P o s i t i o n ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   V e r t e x &   p o s i t i o n   =   ( * t h i s ) . P o s i t i o n ( ) ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
 
         r e t u r n   O b j e c t M o b i l i t y P o s i t i o n ( 
                 c u r r e n t T i m e , 
                 c u r r e n t T i m e , 
                 p o s i t i o n . x , 
                 p o s i t i o n . y , 
                 p o s i t i o n . z , 
                 t r u e / * t h e H e i g h t C o n t a i n s G r o u n d H e i g h t M e t e r s * / , 
                 9 0   -   a g e n t P t r - > d i r e c t i o n R a d i a n s * ( 1 8 0 . / P I ) , 
                 0 . 0 ,   0 . 0 ,   0 . 0 ,   0 . 0 ) ; 
 } 
 
 O b j e c t M o b i l i t y P o s i t i o n   A g e n t R e s o u r c e : : M o b i l i t y P o s i t i o n F o r T i m e ( c o n s t   S i m T i m e &   t i m e )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   V e r t e x &   p o s i t i o n   =   ( * t h i s ) . P o s i t i o n ( ) ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
 
         r e t u r n   O b j e c t M o b i l i t y P o s i t i o n ( 
                 c u r r e n t T i m e , 
                 c u r r e n t T i m e , 
                 p o s i t i o n . x , 
                 p o s i t i o n . y , 
                 p o s i t i o n . z , 
                 t r u e / * t h e H e i g h t C o n t a i n s G r o u n d H e i g h t M e t e r s * / , 
                 ( 9 0   -   a g e n t P t r - > d i r e c t i o n R a d i a n s * ( 1 8 0 . / P I ) ) , 
                 0 . 0 ,   0 . 0 ,   0 . 0 ,   0 . 0 ) ; 
 } 
 
 A g e n t B e h a v i o r T y p e   A g e n t R e s o u r c e : : G e t B e h a v i o r T y p e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         i f   ( a g e n t P t r - > c u r r e n t B e h a v i o r P t r   = =   n u l l p t r )   { 
                 r e t u r n   A G E N T _ B E H A V I O R _ N O T H I N G ; 
         } 
 
         r e t u r n   a g e n t P t r - > c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( ) ; 
 } 
 
 b o o l   A g e n t R e s o u r c e : : W a i t i n g A t E n t r a n c e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > W a i t i n g A t E n t r a n c e ( ) ; 
 } 
 
 b o o l   A g e n t R e s o u r c e : : E x c e e d e d W a i t E n t r a n c e T i m e ( )   c o n s t 
 { 
         a s s e r t ( ( * t h i s ) . W a i t i n g A t E n t r a n c e ( ) ) ; 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         / /   E n t r a n c e   w a i t   c h e c k   s h o u l d   b e   e x e c u t e d   a f t e r   a t   l e a s t   a   t i m e   s t e p . 
 
         c o n s t   S i m T i m e   w a i t T i m e   =   s t d : : m a x ( 
                 a g e n t P t r - > s i m u l a t o r P t r - > T i m e S t e p ( ) , 
                 ( * t h i s ) . E n t r a n c e W a i t T i m e ( ) ) ; 
 
         r e t u r n   ( ( * t h i s ) . C u r r e n t T i m e ( )   > =   ( a g e n t P t r - > e n t r a n c e W a i t S t a r t T i m e   +   w a i t T i m e ) ) ; 
 } 
 
 b o o l   A g e n t R e s o u r c e : : E x c e e d e d W a i t V e h i c l e E n t r a n c e T i m e ( )   c o n s t 
 { 
         a s s e r t ( ( * t h i s ) . W a i t i n g A t E n t r a n c e ( ) ) ; 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         / /   E n t r a n c e   w a i t   c h e c k   s h o u l d   b e   e x e c u t e d   a f t e r   a t   l e a s t   a   t i m e   s t e p . 
 
         c o n s t   S i m T i m e   w a i t T i m e   =   s t d : : m a x ( 
                 a g e n t P t r - > s i m u l a t o r P t r - > T i m e S t e p ( ) , 
                 ( * t h i s ) . V e h i c l e E n t r a n c e W a i t T i m e ( ) ) ; 
 
         r e t u r n   ( ( * t h i s ) . C u r r e n t T i m e ( )   > =   ( a g e n t P t r - > e n t r a n c e W a i t S t a r t T i m e   +   w a i t T i m e ) ) ; 
 } 
 
 c o n s t   G i s P o s i t i o n I d T y p e &   A g e n t R e s o u r c e : : D e s t P o s i t i o n I d ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > d e s t P o s i t i o n I d ; 
 } 
 
 c o n s t   G i s P o s i t i o n I d T y p e &   A g e n t R e s o u r c e : : E x t r a D e s t P o i I d ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > e x t r a D e s t P o i I d ; 
 } 
 
 c o n s t   G i s P o s i t i o n I d T y p e &   A g e n t R e s o u r c e : : H o m e P o s i t i o n I d ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > G e t H o m e P o s i t i n I d ( ) ; 
 } 
 
 R o u t e N u m b e r T y p e     A g e n t R e s o u r c e : : C u r r e n t R o u t e N u m b e r ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > c u r r e n t R o u t e N u m b e r ; 
 } 
 
 c o n s t   A g e n t R o u t e &   A g e n t R e s o u r c e : : C u r r e n t R o u t e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a s s e r t ( ! a g e n t P t r - > c u r r e n t R o u t e L i s t . r o u t e P t r s . e m p t y ( ) ) ; 
         r e t u r n   * a g e n t P t r - > c u r r e n t R o u t e L i s t . r o u t e P t r s . f r o n t ( ) ; 
 } 
 
 S t o p I d T y p e   A g e n t R e s o u r c e : : G e t N e x t R o u t e S t o p I d ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
         a s s e r t ( a g e n t P t r - > c u r r e n t R o u t e L i s t . r o u t e P t r s . s i z e ( )   >   1 ) ; 
 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t R o u t e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   a g e n t P t r - > c u r r e n t R o u t e L i s t . r o u t e P t r s . b e g i n ( ) ; 
         i t e r + + ; 
 
         r e t u r n   ( * i t e r ) - > G e t S t a r t S t o p I d ( ) ; 
 } 
 
 c o n s t   s e t < G i s P o s i t i o n I d T y p e > &   A g e n t R e s o u r c e : : U n r e a c h a b l e D e s t i n a t i o n I d s ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > u n r e a c h a b l e D e s t i n a t i o n I d s ; 
 } 
 
 c o n s t   A g e n t T a s k P u r p o s e T y p e &   A g e n t R e s o u r c e : : C u r r e n t P u r p o s e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > C u r r e n t T a s k ( ) . G e t P u r p o s e ( ) ; 
 } 
 
 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   A g e n t R e s o u r c e : : G e t R a n d o m N u m b e r G e n e r a t o r ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > a R a n d o m N u m b e r G e n e r a t o r ; 
 } 
 
 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   A g e n t R e s o u r c e : : G e t R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > a R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ; 
 } 
 
 S i m T i m e   A g e n t R e s o u r c e : : L a s t D e l a y ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         r e t u r n   a g e n t P t r - > l a s t D e l a y ; 
 } 
 
 S i m T i m e   A g e n t R e s o u r c e : : N e x t D e l a y ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         i f   ( a g e n t P t r - > c u r r e n t B e h a v i o r P t r   = =   n u l l p t r )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
         i f   ( a g e n t P t r - > c u r r e n t B e h a v i o r P t r - > G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ F R E E W A L K )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         c o n s t   A g e n t R o u t e C o s t &   r o u t e C o s t   =   a g e n t P t r - > c u r r e n t B e h a v i o r P t r - > G e t R o u t e ( ) . t o t a l C o s t ; 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
 
         r e t u r n   s t d : : m a x ( Z E R O _ T I M E ,   c u r r e n t T i m e   -   r o u t e C o s t . A r r i v a l T i m e ( ) ) ; 
 } 
 
 S i m T i m e   A g e n t R e s o u r c e : : T r i p D e l a y ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         i f   ( a g e n t P t r - > c u r r e n t B e h a v i o r P t r   = =   n u l l p t r )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         i f   ( ! a g e n t P t r - > t i m e T o S e a r c h R o u t e . s p e c i f i e d A r r i v a l T i m e )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         c o n s t   A g e n t R o u t e C o s t &   r o u t e C o s t   =   a g e n t P t r - > c u r r e n t R o u t e L i s t . t o t a l C o s t ; 
 
         r e t u r n   s t d : : m a x ( Z E R O _ T I M E ,   r o u t e C o s t . A r r i v a l T i m e ( )   -   a g e n t P t r - > t i m e T o S e a r c h R o u t e . a r r i v a l T i m e ) ; 
 } 
 
 S i m T i m e   A g e n t R e s o u r c e : : A r r i v a l D e l a y ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         i f   ( a g e n t P t r - > c u r r e n t B e h a v i o r P t r   = =   n u l l p t r )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         i f   ( ! a g e n t P t r - > t i m e T o S e a r c h R o u t e . s p e c i f i e d A r r i v a l T i m e )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         c o n s t   S i m T i m e   c u r r e n t T i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
 
         r e t u r n   s t d : : m a x ( Z E R O _ T I M E ,   c u r r e n t T i m e   -   a g e n t P t r - > t i m e T o S e a r c h R o u t e . a r r i v a l T i m e ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t P o s i t i o n ( c o n s t   V e r t e x &   p o s i t i o n ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         ( * t h i s ) . S t a t u s ( ) . n e x t P o s i t i o n   =   p o s i t i o n ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t V e r t e x I d ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > S e t V e r t e x I d ( v e r t e x I d ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t C o n g e s t i o n ( c o n s t   d o u b l e   v a l u e ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ H E A L T H _ F A C T O R _ C O N G E S T I O N ]   =   v a l u e ; 
 
         a g e n t P t r - > c o n g e s t i o n T r a c e . S e t V a l u e ( ( * t h i s ) . C o n g e s t i o n ( ) ) ; 
 } 
 
 b o o l   A g e n t R e s o u r c e : : E x c e e d e d R o u t e R e c a l c u l a t i o n T i m e ( )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   S i m T i m e   r e c a l c u l a t i o n T i m e   =   ( * t h i s ) . R o u t e R e c a l c u l a t i o n T i m e ( ) ; 
 
         i f   ( r e c a l c u l a t i o n T i m e   < =   Z E R O _ T I M E )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         r e t u r n   ( ( * t h i s ) . C u r r e n t T i m e ( )   >   a g e n t P t r - > l a s t R o u t e C a l c u l a t e d T i m e   +   r e c a l c u l a t i o n T i m e ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t L a s t P a t h Q u e r y T r i g g e r T i m e ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > l a s t P a t h Q u e r y T r i g g e r T i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
 } 
 
 b o o l   A g e n t R e s o u r c e : : I s P a t h Q u e r y T r i g g e r A v a i l a b l e ( 
         c o n s t   d o u b l e   c o n g e s t i o n , 
         c o n s t   S i m T i m e &   v e h i c l e D e l a y )   c o n s t 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   d o u b l e   p a t h Q u e r y P r o b a b i l i t y   =   ( * t h i s ) . P a t h Q u e r y P r o b a b i l i t y ( ) ; 
 
         i f   ( p a t h Q u e r y P r o b a b i l i t y   < =   0 )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         c o n s t   S i m T i m e   m i n P a t h Q u e r y D u r a t i o n   =   ( * t h i s ) . M i n P a t h Q u e r y I n t e r v a l ( ) ; 
 
         i f   ( ( * t h i s ) . C u r r e n t T i m e ( )   < =   a g e n t P t r - > l a s t P a t h Q u e r y T r i g g e r T i m e   +   m i n P a t h Q u e r y D u r a t i o n )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d o m n u m b e r G e n e r a t o r   =   ( * t h i s ) . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
         c o n s t   d o u b l e   a V a l u e   =   r a n d o m n u m b e r G e n e r a t o r . G e n e r a t e R a n d o m D o u b l e ( ) ; 
 
         i f   ( a V a l u e   >   p a t h Q u e r y P r o b a b i l i t y )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         c o n s t   b o o l   i s A v a i l a b l e   = 
                 ( ( * t h i s ) . L a s t D e l a y ( )   > =   ( * t h i s ) . L a s t D e l a y Q u e r y T r i g g e r ( ) * S E C O N D   | | 
                   ( * t h i s ) . N e x t D e l a y ( )   > =   ( * t h i s ) . N e x t D e l a y Q u e r y T r i g g e r ( ) * S E C O N D   | | 
                   ( * t h i s ) . T r i p D e l a y ( )   > =   ( * t h i s ) . T r i p D e l a y Q u e r y T r i g g e r ( ) * S E C O N D   | | 
                   v e h i c l e D e l a y   > =   ( * t h i s ) . V e h i c l e D e l a y Q u e r y T r i g g e r ( ) * S E C O N D   | | 
                   c o n g e s t i o n   > =   ( * t h i s ) . C o n g e s t i o n Q u e r y T r i g g e r ( )   | | 
                   ( * t h i s ) . U t i l i t y 1 ( )   > =   ( * t h i s ) . U t i l i t y 1 Q u e r y T r i g g e r ( )   | | 
                   ( * t h i s ) . U t i l i t y 2 ( )   > =   ( * t h i s ) . U t i l i t y 2 Q u e r y T r i g g e r ( ) ) ; 
 
         o s t r i n g s t r e a m   o u t S t r e a m ; 
         o u t S t r e a m   < <   " P a t h Q u e r y   =   "   < <   i s A v a i l a b l e 
                             < <   " ,   L a s t D e l a y   =   "   < <   ( * t h i s ) . L a s t D e l a y ( )   /   S E C O N D 
                             < <   " ,   N e x t D e l a y   =   "   < <   ( * t h i s ) . N e x t D e l a y ( )   /   S E C O N D 
                             < <   " ,   T r i p D e l a y   =   "   < <   ( * t h i s ) . T r i p D e l a y ( )   /   S E C O N D 
                             < <   " ,   A r r i v a l D e l a y   =   "   < <   ( * t h i s ) . A r r i v a l D e l a y ( )   /   S E C O N D 
                             < <   " ,   V e h i c l e D e l a y   =   "   < <   v e h i c l e D e l a y   /   S E C O N D 
                             < <   " ,   C o n g e s t i o n   =   "   < <   c o n g e s t i o n 
                             < <   " ,   U t i l i t y   =   "   < <   ( * t h i s ) . U t i l i t y 1 ( )   < <   "   /   "   < <   ( * t h i s ) . U t i l i t y 2 ( ) ; 
 
         ( * t h i s ) . O u t p u t T r a c e ( o u t S t r e a m . s t r ( ) ) ; 
 
         r e t u r n   i s A v a i l a b l e ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : A s s i g n T a x i ( c o n s t   s h a r e d _ p t r < T a x i > &   i n i t T a x i P t r ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         i f   ( a g e n t P t r - > c u r r e n t B e h a v i o r P t r   ! =   n u l l p t r )   { 
                 a g e n t P t r - > c u r r e n t B e h a v i o r P t r - > A s s i g n T a x i ( i n i t T a x i P t r ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : R e c a l c u l a t e R o u t e ( c o n s t   S i m T i m e &   r e c a l c u l a t e S t a r t T i m e ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > R e c a l c u l a t e R o u t e ( r e c a l c u l a t e S t a r t T i m e ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : R e c a l c u l a t e R o u t e ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > R e c a l c u l a t e R o u t e ( ( * t h i s ) . C u r r e n t T i m e ( ) ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : R e c a l c u l a t e R o u t e W i t h B e h a v i o r ( c o n s t   A g e n t B e h a v i o r T y p e &   b e h a v i o r ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > R e c a l c u l a t e R o u t e ( ( * t h i s ) . C u r r e n t T i m e ( ) ,   b e h a v i o r ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : R e c a l c u l a t e R o u t e W i t h N o t A v a i l a b l e B e h a v i o r S p e c i f i c a t i o n ( 
         c o n s t   s e t < A g e n t B e h a v i o r T y p e > &   n o t A v a i l a b l e B e h a v i o r T y p e s ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > n o t A v a i l a b l e B e h a v o r T y p e s F o r N e x t R o u t e C a l c u l a t i o n   =   n o t A v a i l a b l e B e h a v i o r T y p e s ; 
         a g e n t P t r - > R e c a l c u l a t e R o u t e ( ( * t h i s ) . C u r r e n t T i m e ( ) ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : A r r i v e d A t D e a d E n d N o t i f i c a t i o n ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > &   c o m m u n i c a t i o n N o d e P t r s   =   a g e n t P t r - > c o m m u n i c a t i o n N o d e P t r s ; 
 
         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > A r r i v e d A t D e a d E n d N o t i f i c a t i o n ( ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : A r r i v e d A t D e s t i n a t i o n N o t i f i c a t i o n ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > &   c o m m u n i c a t i o n N o d e P t r s   =   a g e n t P t r - > c o m m u n i c a t i o n N o d e P t r s ; 
 
         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > A r r i v e d A t D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : E n t e r e d T o D e s t i n a t i o n N o t i f i c a t i o n ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > &   c o m m u n i c a t i o n N o d e P t r s   =   a g e n t P t r - > c o m m u n i c a t i o n N o d e P t r s ; 
 
         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > E n t e r e d T o D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : A r r i v e d A t G i s P o s i t i o n N o t i f i c a t i o n ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > &   c o m m u n i c a t i o n N o d e P t r s   =   a g e n t P t r - > c o m m u n i c a t i o n N o d e P t r s ; 
         c o n s t   G i s P o s i t i o n I d T y p e   c u r r e n t P o s i t i o n I d   =   a g e n t P t r - > c u r r e n t P o s i t i o n I d ; 
 
         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > A r r i v e d A t G i s P o s i t i o n N o t i f i c a t i o n ( c u r r e n t P o s i t i o n I d ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : R e c e i v e P h y s i c a l D a t a ( S e n s i n g S h a r e d I n f o T y p e &   b r o a d c a s t D a t a ) 
 { 
         a s s e r t ( ( * t h i s ) . I s A v a i l a b l e ( ) ) ; 
 
         / /   r e c e i v i n g   p r o c e s s 
 } 
 
 v o i d   A g e n t R e s o u r c e : : U n r e a c h a b l e D e s t i n a t i o n N o t i f i c a t i o n ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > &   c o m m u n i c a t i o n N o d e P t r s   =   a g e n t P t r - > c o m m u n i c a t i o n N o d e P t r s ; 
         c o n s t   G i s P o s i t i o n I d T y p e &   d e s t P o s i t i o n I d   =   a g e n t P t r - > d e s t P o s i t i o n I d ; 
 
         i f   ( d e s t P o s i t i o n I d   = =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
                 r e t u r n ; 
         } 
 
         t y p e d e f   s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                 i t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 ( * i t e r ) - > U n r e a c h a b l e D e s t i n a t i o n N o t i f i c a t i o n ( d e s t P o s i t i o n I d ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t D e s t i n a t i o n ( c o n s t   V e r t e x &   p o s i t i o n ,   c o n s t   b o o l   b y C o m m u n i c a t i o n ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   a g e n t P t r - > t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         v e c t o r < G i s O b j e c t T y p e >   p r i o r i t i z e d D e s t i n a t i o n O b j e c t T y p e s ; 
         p r i o r i t i z e d D e s t i n a t i o n O b j e c t T y p e s . p u s h _ b a c k ( G I S _ P O I ) ; 
         p r i o r i t i z e d D e s t i n a t i o n O b j e c t T y p e s . p u s h _ b a c k ( G I S _ B U I L D I N G ) ; 
         p r i o r i t i z e d D e s t i n a t i o n O b j e c t T y p e s . p u s h _ b a c k ( G I S _ P A R K ) ; 
 
         c o n s t   G i s P o s i t i o n I d T y p e   p o s i t i o n I d   = 
                 s u b s y s t e m . G e t P o s i t i o n I d ( p o s i t i o n ,   p r i o r i t i z e d D e s t i n a t i o n O b j e c t T y p e s ) ; 
 
         i f   ( p o s i t i o n I d . I s I n v a l i d ( ) )   { 
                 r e t u r n ; 
         } 
 
         ( * t h i s ) . S e t D e s t i n a t i o n ( p o s i t i o n I d ,   p o s i t i o n ,   b y C o m m u n i c a t i o n ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t D e s t i n a t i o n ( 
         c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
         c o n s t   V e r t e x &   p o s i t i o n , 
         c o n s t   b o o l   b y C o m m u n i c a t i o n ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   a g e n t P t r - > t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
         c o n s t   V e r t e x I d T y p e   d e s t V e r t e x I d   =   s u b s y s t e m . G e t N e a r e s t V e r t e x I d ( p o s i t i o n I d ,   p o s i t i o n ) ; 
 
         a g e n t P t r - > C h a n g e T o S p e c i f i c D e s t i n a t i o n ( p o s i t i o n I d ,   d e s t V e r t e x I d ,   b y C o m m u n i c a t i o n ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : A d d U n r e a c h a b l e P o s i t i o n s ( 
         c o n s t   l i s t < G i s P o s i t i o n I d T y p e > &   u n r e a c h a b l e P o s i t i o n I d s , 
         c o n s t   b o o l   b y C o m m u n i c a t i o n ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > A d d U n r e a c h a b l e P o s i t i o n s ( u n r e a c h a b l e P o s i t i o n I d s ,   b y C o m m u n i c a t i o n ) ; 
 } 
 
 
 v o i d   A g e n t R e s o u r c e : : U p d a t e C u r r e n t P o s i t i o n I d T o D e s i r e d P o s i t i o n I d ( ) 
 { 
         a g e n t P t r - > c u r r e n t P o s i t i o n I d   =   a g e n t P t r - > d e s i r e d N e x t P o s i t i o n I d ; 
 } 
 
 
 v o i d   A g e n t R e s o u r c e : : S e t C u r r e n t P o s i t i o n I d ( c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > c u r r e n t P o s i t i o n I d   =   p o s i t i o n I d ; 
 
         / /   M a k e   s u r e   d e s i r e d   p o s i t i o n   i s   e q u a l   t o   c u r r e n t   p o s i t i o n   w h e n 
         / /   c u r r e n t   p o s i t i o n   i s   s e t ,   i . e .   o v e r r i d e   c u r r e n t   d e s i r e d   p o s i t i o n . 
 
         a g e n t P t r - > d e s i r e d N e x t P o s i t i o n I d   =   a g e n t P t r - > c u r r e n t P o s i t i o n I d ; 
 } 
 
 
 v o i d   A g e n t R e s o u r c e : : S e t D e s i r e d N e x t P o s i t i o n I d ( c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
         a g e n t P t r - > d e s i r e d N e x t P o s i t i o n I d   =   p o s i t i o n I d ; 
 } 
 
 
 v o i d   A g e n t R e s o u r c e : : S e t E x t r a P o i I d ( c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > e x t r a C u r r e n t P o i I d   =   p o s i t i o n I d ; 
 } 
 v o i d   A g e n t R e s o u r c e : : S e t C u r r e n t P o s i t i o n I d ( c o n s t   G i s O b j e c t T y p e &   o b j e c t T y p e ,   c o n s t   V a r i a n t I d T y p e &   v a r i a n t I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         ( * t h i s ) . S e t C u r r e n t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( o b j e c t T y p e ,   v a r i a n t I d ) ) ; 
 } 
 
 
 v o i d   A g e n t R e s o u r c e : : S e t D e s i r e d N e x t P o s i t i o n I d ( c o n s t   G i s O b j e c t T y p e &   o b j e c t T y p e ,   c o n s t   V a r i a n t I d T y p e &   v a r i a n t I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         ( * t h i s ) . S e t D e s i r e d N e x t P o s i t i o n I d ( G i s P o s i t i o n I d T y p e ( o b j e c t T y p e ,   v a r i a n t I d ) ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t D i r e c t i o n R a d i a n s ( c o n s t   d o u b l e   d i r e c t i o n R a d i a n s ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > d i r e c t i o n R a d i a n s   =   d i r e c t i o n R a d i a n s ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : S e t O w n e r A g e n t ( 
         c o n s t   A g e n t I d T y p e &   o w n e r A g e n t I d ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > s i m u l a t o r P t r - > S e t O w n e r A g e n t ( * t h i s ,   o w n e r A g e n t I d ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : R e m o v e O w n e r A g e n t ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         i f   ( a g e n t P t r - > H a s P a r e n t ( ) )   { 
                 ( * t h i s ) . S e t O w n e r A g e n t ( ) ; 
         }   e l s e   { 
                 a g e n t P t r - > s i m u l a t o r P t r - > R e m o v e O w n e r A g e n t C h a n g e ( * t h i s ) ; 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : W a i t E n t r a n c e ( ) 
 { 
         i f   ( ( * t h i s ) . W a i t i n g A t E n t r a n c e ( ) )   { 
                 r e t u r n ; 
         } 
 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > e n t r a n c e W a i t S t a r t T i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
 } 
 
 v o i d   A g e n t R e s o u r c e : : A l l o w e d E n t r a n c e ( ) 
 { 
         i f   ( ! W a i t i n g A t E n t r a n c e ( ) )   { 
                 r e t u r n ; 
         } 
 
         ( * t h i s ) . E n d E n t r a n c e W a i t i n g ( ) ; 
 
         i f   ( ( * t h i s ) . G e t B e h a v i o r T y p e ( )   = =   A G E N T _ B E H A V I O R _ V E H I C L E )   { 
 
                 / /   D r i v e r   a g e n t   e n t e r d   t o   p a r k i n g . 
                 / /   A f t e r   p a r k i n g   a   c a r ,   t h e   a g e n t   w i l l   g o   t o   d e s t i n a t i o n   p o s i t i o n   w i t h   w a l k i n g . 
 
         } 
         e l s e   { 
                 a s s e r t ( G e t C u r r e n t P o s i t i o n I d ( )   = =   G e t D e s i r e d P o s i t i o n I d ( ) ) ; 
 
                 i f   ( G e t C u r r e n t P o s i t i o n I d ( )   = =   D e s t P o s i t i o n I d ( ) )   { 
                         ( * t h i s ) . E n t e r e d T o D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
                 } 
         } 
 } 
 
 v o i d   A g e n t R e s o u r c e : : E n d E n t r a n c e W a i t i n g ( ) 
 { 
         ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
         a g e n t P t r - > e n t r a n c e W a i t S t a r t T i m e   =   I N F I N I T E _ T I M E ; 
 
 } / / R e s e t E n t r a n c e S t a t e / / 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 e n u m   A g e n t P a r a m e t e r V a l u e T y p e   { 
         A G E N T _ P A R A M E T E R _ V A L U E _ I N T , 
         A G E N T _ P A R A M E T E R _ V A L U E _ D O U B L E , 
         A G E N T _ P A R A M E T E R _ V A L U E _ S T R I N G , 
 } ; 
 
 c l a s s   N o F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   v a l u e s . f r o n t ( ) ; 
         } 
 } ; 
 c l a s s   P l u s F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   v a l u e s [ 0 ]   +   v a l u e s [ 1 ] ; 
         } 
 } ; 
 c l a s s   M i n u s F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   v a l u e s [ 0 ]   -   v a l u e s [ 1 ] ; 
         } 
 } ; 
 c l a s s   D i v F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 i f   ( v a l u e s [ 1 ]   = =   0 )   { 
                         c e r r   < <   " E r r o r :   o c c u r e d   0   d i v i s i o n .   C h e c k   a g e n t   p r o f i l e   f o r u m u l a . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
                 r e t u r n   v a l u e s [ 0 ]   /   v a l u e s [ 1 ] ; 
         } 
 } ; 
 c l a s s   M u l t i F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   v a l u e s [ 0 ]   *   v a l u e s [ 1 ] ; 
         } 
 } ; 
 c l a s s   M o d F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 i f   ( v a l u e s [ 1 ]   = =   0 )   { 
                         c e r r   < <   " E r r o r :   o c c u r e d   0   m o d .   C h e c k   a g e n t   p r o f i l e   f o r u m u l a . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
                 r e t u r n   i n t ( v a l u e s [ 0 ] )   %   i n t ( v a l u e s [ 1 ] ) ; 
         } 
 } ; 
 c l a s s   E p l u s F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   v a l u e s [ 0 ]   *   s t d : : p o w ( 1 0 ,   v a l u e s [ 1 ] ) ; 
         } 
 } ; 
 c l a s s   E m i n u s F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   v a l u e s [ 0 ]   *   s t d : : p o w ( 1 0 ,   - v a l u e s [ 1 ] ) ; 
         } 
 } ; 
 c l a s s   L o g 1 0 F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
 
                 r e t u r n   l o g 1 0 ( v a l u e s [ 0 ] ) ; 
         } 
 } ; 
 c l a s s   L o g N F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   l o g ( v a l u e s [ 0 ] ) ; 
         } 
 } ; 
 c l a s s   P o w F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   p o w ( v a l u e s [ 0 ] ,   v a l u e s [ 1 ] ) ; 
         } 
 } ; 
 c l a s s   M i n F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   s t d : : m i n ( v a l u e s [ 0 ] ,   v a l u e s [ 1 ] ) ; 
         } 
 } ; 
 c l a s s   M a x F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   s t d : : m a x ( v a l u e s [ 0 ] ,   v a l u e s [ 1 ] ) ; 
         } 
 } ; 
 c l a s s   S q r t F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   ( s q r t ( v a l u e s [ 0 ] ) ) ; 
         } 
 } ; 
 c l a s s   S i n F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   ( s t d : : s i n ( v a l u e s [ 0 ] ) ) ; 
         } 
 } ; 
 c l a s s   C o s F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   ( s t d : : c o s ( v a l u e s [ 0 ] ) ) ; 
         } 
 } ; 
 c l a s s   T a n F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   ( s t d : : t a n ( v a l u e s [ 0 ] ) ) ; 
         } 
 } ; 
 c l a s s   A b s F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   f a b s ( v a l u e s [ 0 ] ) ; 
         } 
 } ; 
 c l a s s   C e i l F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   c e i l ( v a l u e s [ 0 ] ) ; 
         } 
 } ; 
 c l a s s   F l o o r F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   f l o o r ( v a l u e s [ 0 ] ) ; 
         } 
 } ; 
 c l a s s   P i F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   P I ; 
         } 
 } ; 
 c l a s s   E x p F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   ( e x p ( v a l u e s [ 0 ] ) ) ; 
         } 
 } ; 
 c l a s s   U n i F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   d o u b l e ( r a n d G e n . G e n e r a t e R a n d o m I n t ( 
                                                     s t a t i c _ c a s t < i n t > ( v a l u e s [ 0 ] ) , 
                                                     s t a t i c _ c a s t < i n t > ( v a l u e s [ 1 ] ) ) ) ; 
         } 
 } ; 
 c l a s s   U n i d F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 c o n s t   d o u b l e   l a r g e V a l u e   =   s t d : : m a x ( v a l u e s [ 0 ] ,   v a l u e s [ 1 ] ) ; 
                 c o n s t   d o u b l e   s a m l l V a l u e   =   s t d : : m i n ( v a l u e s [ 0 ] ,   v a l u e s [ 1 ] ) ; 
 
                 i f   ( l a r g e V a l u e   = =   s a m l l V a l u e )   { 
                         r e t u r n   s a m l l V a l u e ; 
                 } 
 
                 r e t u r n   ( ( l a r g e V a l u e   -   s a m l l V a l u e )   *   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( )   +   s a m l l V a l u e ) ; 
         } 
 } ; 
 c l a s s   N o r m a l F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
 
                 / /   c e n t r a l   l i m i t   t h e o r e m 
 
                 d o u b l e   t o t a l   =   0 ; 
 
                 f o r   ( i n t   i   =   0 ;   i   <   1 2 ;   i + + )   { 
                         t o t a l   + =   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ; 
                 } 
 
                 r e t u r n   ( v a l u e s [ 1 ]   *   ( t o t a l   -   6 . 0 )   +   v a l u e s [ 0 ] ) ; 
         } 
 } ; 
 c l a s s   E x p D i s t r i b u t i o n F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   ( -   v a l u e s [ 0 ]   *   l o g ( 1   -   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ) ) ; 
         } 
 } ; 
 c l a s s   P o i s s o n F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
 
                 i n t   i   =   0 ; 
                 d o u b l e   a V a l u e   =   e x p ( v a l u e s [ 0 ] ) * r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ; 
 
                 f o r ( ;   a V a l u e   >   1 . 0 ;   i + + )   { 
                         a V a l u e   * =   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ; 
                 } 
 
                 r e t u r n   s t a t i c _ c a s t < d o u b l e > ( i ) ; 
         } 
 } ; 
 c l a s s   E r l a n g F o r m u l a   :   p u b l i c   A g e n t V a l u e F o r m u l a : : F o r m u l a   { 
 p u b l i c : 
         v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                 c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
 
                 c o n s t   i n t   p h a s e   =   s t a t i c _ c a s t < i n t > ( v a l u e s [ 1 ] ) ; 
                 d o u b l e   a V a l u e   =   1 . 0 ; 
 
                 f o r ( i n t   i   =   0 ;   i   <   p h a s e ;   i + + )   { 
                         a V a l u e   * =   ( 1   -   r a n d G e n . G e n e r a t e R a n d o m D o u b l e ( ) ) ; 
                 } 
 
                 r e t u r n   ( -   v a l u e s [ 0 ]   /   s t a t i c _ c a s t < d o u b l e > ( p h a s e )   *   l o g ( a V a l u e ) ) ; 
         } 
 } ; 
 
 c o n s t   s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a >   A g e n t V a l u e F o r m u l a : : f o r m u l a P t r s [ ]   =   { 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   N o F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   P l u s F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   M i n u s F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   D i v F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   M u l t i F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   M o d F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   E p l u s F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   E m i n u s F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   L o g 1 0 F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   L o g N F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   P o w F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   M i n F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   M a x F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   S q r t F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   S i n F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   C o s F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   T a n F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   A b s F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   C e i l F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   F l o o r F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   P i F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   E x p F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   U n i F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   U n i d F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   N o r m a l F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   E x p D i s t r i b u t i o n F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   P o i s s o n F o r m u l a ( ) ) , 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a : : F o r m u l a > ( n e w   E r l a n g F o r m u l a ( ) ) , 
 } ; 
 
 s t a t i c   i n l i n e 
 b o o l   C a n R e m o v e O u t m o s t A r c ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         i f   ( a S t r i n g . e m p t y ( )   | | 
                 ! ( a S t r i n g [ 0 ]   = =   ' ( '   & &   a S t r i n g [ a S t r i n g . l e n g t h ( )   -   1 ]   = =   ' ) ' ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         s i z e _ t   n u m b e r S t a r t A r c s   =   1 ; 
 
         f o r ( s i z e _ t   i   =   1 ;   i   <   a S t r i n g . s i z e ( )   -   1 ;   i + + )   { 
 
                 i f   ( a S t r i n g [ i ]   = =   ' ( ' )   { 
                         n u m b e r S t a r t A r c s + + ; 
                 }   e l s e   i f   ( a S t r i n g [ i ]   = =   ' ) ' )   { 
                         n u m b e r S t a r t A r c s - - ; 
 
                         i f   ( n u m b e r S t a r t A r c s   = =   0 )   { 
                                 r e t u r n   f a l s e ; 
                         } 
                 } 
         } 
 
         r e t u r n   ( n u m b e r S t a r t A r c s   = =   1 ) ; 
 } 
 
 s t a t i c   i n l i n e 
 b o o l   I s F u n c t i o n S t r i n g ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         i f   ( a S t r i n g . e m p t y ( )   | |   ! i s a l p h a ( a S t r i n g [ 0 ] ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         s i z e _ t   f u n c t i o n N a m e E n d P o s   =   a S t r i n g . f i n d _ f i r s t _ o f ( " + - * / % ^ ( . " ) ; 
 
         i f   ( f u n c t i o n N a m e E n d P o s   ! =   s t r i n g : : n p o s   & & 
                 a S t r i n g [ f u n c t i o n N a m e E n d P o s ]   = =   ' ( ' )   { 
 
                 c o n s t   s t r i n g   f u n c t i o n C o n t e n t s   =   a S t r i n g . s u b s t r ( f u n c t i o n N a m e E n d P o s ) ; 
 
                 r e t u r n   C a n R e m o v e O u t m o s t A r c ( f u n c t i o n C o n t e n t s ) ; 
         } 
 
         r e t u r n   f a l s e ; 
 } 
 
 s t a t i c   i n l i n e 
 b o o l   I s V a r i a b l e S t r i n g ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         i f   ( a S t r i n g . e m p t y ( )   | | 
                 ! ( i s a l p h a ( a S t r i n g [ 0 ] )   | |   a S t r i n g [ 0 ]   = =   ' _ ' ) )     { 
                 r e t u r n   f a l s e ; 
         } 
 
         r e t u r n   ( a S t r i n g . f i n d _ f i r s t _ o f ( " + - * / % ^ ( . " )   = =   s t r i n g : : n p o s ) ; 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   C o n v e r t T i m e S t r i n g T o D o u b l e S e c ( 
         c o n s t   s t r i n g &   a S t r i n g ,   d o u b l e &   v a l u e ,   b o o l &   s u c c e s s ) 
 { 
         d e q u e < s t r i n g >   t i m e S t r i n g s ; 
         T o k e n i z e T o T r i m m e d L o w e r S t r i n g W i t h A r c ( a S t r i n g ,   " : " ,   t i m e S t r i n g s ) ; 
 
         i n t   h o u r   =   0 ; 
         i n t   m i n u t e   =   0 ; 
         i n t   s e c o n d   =   0 ; 
 
         C o n v e r t S t r i n g T o I n t ( t i m e S t r i n g s [ 0 ] ,   h o u r ,   s u c c e s s ) ; 
         i f   ( ! s u c c e s s )   { 
                 r e t u r n ; 
         } 
 
         C o n v e r t S t r i n g T o I n t ( t i m e S t r i n g s [ 1 ] ,   m i n u t e ,   s u c c e s s ) ; 
         i f   ( ! s u c c e s s )   { 
                 r e t u r n ; 
         } 
 
         i f   ( t i m e S t r i n g s . s i z e ( )   > =   3 )   { 
                 C o n v e r t S t r i n g T o I n t ( t i m e S t r i n g s [ 2 ] ,   s e c o n d ,   s u c c e s s ) ; 
                 i f   ( ! s u c c e s s )   { 
                         r e t u r n ; 
                 } 
         } 
 
         s u c c e s s   =   t r u e ; 
         v a l u e   =   6 0 * 6 0 * h o u r   +   6 0 * m i n u t e   +   s e c o n d ; 
 } 
 
 s t a t i c   i n l i n e 
 b o o l   I s E n u m V a l u e ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         i f   ( I s F u n c t i o n S t r i n g ( a S t r i n g ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         b o o l   s u c c e s s ; 
         d o u b l e   a V a l u e ; 
 
         C o n v e r t S t r i n g T o D o u b l e ( a S t r i n g ,   a V a l u e ,   s u c c e s s ) ; 
 
         r e t u r n   ! s u c c e s s ; 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   T o k e n i z e T o C o n d i t i o n O r T a s k S t r i n g ( 
         c o n s t   s t r i n g &   a S t r i n g , 
         v e c t o r < s t r i n g > &   t o k e n s ) 
 { 
         t o k e n s . c l e a r ( ) ; 
 
         s i z e _ t   l a s t T o n e S t a r t P o s   =   0 ; 
         s i z e _ t   c u r r e n t P o s   =   0 ; 
 
         w h i l e   ( c u r r e n t P o s   <   a S t r i n g . s i z e ( ) )   { 
                 c o n s t   s i z e _ t   a r c P o s   =   a S t r i n g . f i n d ( ' ( ' ,   l a s t T o n e S t a r t P o s ) ; 
 
                 s i z e _ t   n u m b e r A r c s   =   0 ; 
 
                 f o r ( c u r r e n t P o s   =   a r c P o s ;   c u r r e n t P o s   <   a S t r i n g . s i z e ( ) ;   c u r r e n t P o s + + )   { 
                         c o n s t   c h a r   a C h a r   =   a S t r i n g [ c u r r e n t P o s ] ; 
 
                         i f   ( a C h a r   = =   ' ( ' )   { 
                                 n u m b e r A r c s + + ; 
                         }   e l s e   i f   ( a C h a r   = =   ' ) ' )   { 
                                 n u m b e r A r c s - - ; 
                         } 
 
                         i f   ( n u m b e r A r c s   = =   0 )   { 
                                 t o k e n s . p u s h _ b a c k ( a S t r i n g . s u b s t r ( l a s t T o n e S t a r t P o s ,   c u r r e n t P o s   -   l a s t T o n e S t a r t P o s   +   1 ) ) ; 
                                 l a s t T o n e S t a r t P o s   =   c u r r e n t P o s   +   1 ; 
                                 b r e a k ; 
                         } 
                 } 
         } 
 } 
 
 s t a t i c   i n l i n e 
 s t r i n g   N o n s p a c e d S t r i n g ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         s t r i n g   n o n s p a c e d S t r i n g ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a S t r i n g . s i z e ( ) ;   i + + )   { 
                 i f   ( a S t r i n g [ i ]   ! =   '   ' )   { 
                         n o n s p a c e d S t r i n g . p u s h _ b a c k ( a S t r i n g [ i ] ) ; 
                 } 
         } 
 
         r e t u r n   n o n s p a c e d S t r i n g ; 
 } 
 
 s t a t i c   i n l i n e 
 s t r i n g   N o n s p a c e d R a w F o r m u l a S t r i n g ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         s t r i n g   n o n s p a c e d S t r i n g   =   N o n s p a c e d S t r i n g ( a S t r i n g ) ; 
 
         s i z e _ t   n u m b e r S t a r t A r c s   =   0 ; 
         s i z e _ t   n u m b e r E n d A r c s   =   0 ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   n o n s p a c e d S t r i n g . s i z e ( ) ;   i + + )   { 
                 c o n s t   c h a r   a C h a r   =   n o n s p a c e d S t r i n g [ i ] ; 
 
                 i f   ( a C h a r   = =   ' ( ' )   { 
                         n u m b e r S t a r t A r c s + + ; 
                 }   e l s e     i f   ( a C h a r   = =   ' ) ' )   { 
                         n u m b e r E n d A r c s + + ; 
                 } 
         } 
 
         i f   ( n u m b e r S t a r t A r c s   ! =   n u m b e r E n d A r c s )   { 
                 c e r r   < <   " E r r o r :   l a c k   o f   a r c s   i n   f o r m u l a   "   < <   a S t r i n g   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         w h i l e   ( C a n R e m o v e O u t m o s t A r c ( n o n s p a c e d S t r i n g ) )   { 
 
                 n o n s p a c e d S t r i n g   =   N o n s p a c e d S t r i n g ( n o n s p a c e d S t r i n g . s u b s t r ( 1 ,   n o n s p a c e d S t r i n g . l e n g t h ( )   -   2 ) ) ; 
         } 
 
         r e t u r n   n o n s p a c e d S t r i n g ; 
 } 
 
 A g e n t V a l u e F o r m u l a : : A g e n t V a l u e F o r m u l a ( 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
         c o n s t   d o u b l e   s i m S t a r t T i m e S e c , 
         c o n s t   s t r i n g &   a S t r i n g , 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   c h a r a c t o r I d s , 
         c o n s t   d o u b l e   i n i t D e f a u l t V a l u e ) 
         : 
         i n p u t F o r m u l a S t r i n g ( a S t r i n g ) , 
         d e f a u l t V a l u e ( i n i t D e f a u l t V a l u e ) 
 { 
         i f   ( ! a S t r i n g . e m p t y ( ) )   { 
 
                 s t r i n g   n o n E q u a l S t r i n g   =   N o n s p a c e d R a w F o r m u l a S t r i n g ( a S t r i n g ) ; 
 
                 i f   ( n o n E q u a l S t r i n g [ 0 ]   = =   ' = ' )   { 
                         n o n E q u a l S t r i n g   =   n o n E q u a l S t r i n g . s u b s t r ( 1 ) ; 
                 } 
 
                 i f   ( n o n E q u a l S t r i n g   ! =   " - " )   { 
                         ( * t h i s ) . A d d F o r m u l a U n i t R e c u r s i v e l y ( 
                                 p a r a m e t e r s ,   s i m S t a r t T i m e S e c ,   n o n E q u a l S t r i n g ,   c h a r a c t o r I d s ) ; 
 
                         a s s e r t ( f o r m u l a U n i t s . s i z e ( )   >   0 ) ; 
                         ( * t h i s ) . P r e c a l c u l a t e F o r m u l a U n i t ( 0 ) ; 
                 } 
         } 
 } 
 
 A g e n t V a l u e F o r m u l a : : A g e n t V a l u e F o r m u l a ( 
         c o n s t   s t r i n g &   a S t r i n g , 
         c o n s t   d o u b l e   i n i t D e f a u l t V a l u e ) 
         : 
         i n p u t F o r m u l a S t r i n g ( a S t r i n g ) , 
         d e f a u l t V a l u e ( i n i t D e f a u l t V a l u e ) 
 { 
         L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a >   n o P a r a m e t e r s ; 
         c o n s t   d o u b l e   s i m S t a r t T i m e S e c   =   0 ; 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e >   n o C h a r a c t o r I d s ; 
 
         i f   ( ! a S t r i n g . e m p t y ( ) )   { 
 
                 s t r i n g   n o n E q u a l S t r i n g   =   N o n s p a c e d R a w F o r m u l a S t r i n g ( a S t r i n g ) ; 
 
                 i f   ( n o n E q u a l S t r i n g [ 0 ]   = =   ' = ' )   { 
                         n o n E q u a l S t r i n g   =   n o n E q u a l S t r i n g . s u b s t r ( 1 ) ; 
                 } 
 
                 i f   ( n o n E q u a l S t r i n g   ! =   " - " )   { 
                         ( * t h i s ) . A d d F o r m u l a U n i t R e c u r s i v e l y ( 
                                 n o P a r a m e t e r s ,   s i m S t a r t T i m e S e c ,   n o n E q u a l S t r i n g ,   n o C h a r a c t o r I d s ) ; 
 
                         a s s e r t ( f o r m u l a U n i t s . s i z e ( )   >   0 ) ; 
                         ( * t h i s ) . P r e c a l c u l a t e F o r m u l a U n i t ( 0 ) ; 
                 } 
         } 
 } 
 
 v o i d   A g e n t V a l u e F o r m u l a : : P r e c a l c u l a t e F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d ) 
 { 
         c o n s t   A g e n t R e s o u r c e   e m p t y R e s o u r c e ( n u l l p t r ) ; 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r   n o t U s e d R a n d G e n ( 0 ) ; 
 
         F o r m u l a U n i t &   f o r m u l a U n i t   =   ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) ; 
 
         i f   ( f o r m u l a U n i t . o p e r a t i o n   ! =   F O R M U L A _ O P E R A T I O N _ N O N E )   { 
                 v e c t o r < p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e >   > &   v a l u e s   =   f o r m u l a U n i t . v a l u e s ; 
 
                 f o r ( s i z e _ t   i   =   0 ;   i   <   v a l u e s . s i z e ( ) ;   i + + )   { 
                         p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e > &   a V a l u e   =   v a l u e s [ i ] ; 
                         c o n s t   F o r m u l a U n i t I d T y p e   v a l u e U n i t I d   =   a V a l u e . f i r s t ; 
 
                         i f   ( v a l u e U n i t I d   ! =   N O _ F O R M U L A _ U N I T _ I D )   { 
                                 a s s e r t ( v a l u e U n i t I d   ! =   u n i t I d ) ; 
 
                                 c o n s t   F o r m u l a U n i t &   v a l u e F o r m u l a U n i t   = 
                                         ( * t h i s ) . G e t F o r m u l a U n i t ( v a l u e U n i t I d ) ; 
 
                                 i f   ( M a y B e C o n s t V a l u e ( v a l u e F o r m u l a U n i t . o p e r a t i o n ) )   { 
                                         ( * t h i s ) . P r e c a l c u l a t e F o r m u l a U n i t ( v a l u e U n i t I d ) ; 
                                 } 
                                 i f   ( v a l u e F o r m u l a U n i t . C o m p l e t e d A l l C a l c u l a t i o n ( ) )   { 
                                         a V a l u e . s e c o n d   =   ( * t h i s ) . C a l c u l a t e ( v a l u e U n i t I d ,   e m p t y R e s o u r c e ,   n o t U s e d R a n d G e n ) ; 
                                         a V a l u e . f i r s t   =   N O _ F O R M U L A _ U N I T _ I D ; 
                                 } 
                         } 
                 } 
         } 
 } 
 
 A g e n t V a l u e F o r m u l a : : F o r m u l a U n i t &   A g e n t V a l u e F o r m u l a : : G e t F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d ) 
 { 
         a s s e r t ( u n i t I d   ! =   N O _ F O R M U L A _ U N I T _ I D ) ; 
         a s s e r t ( u n i t I d   <   f o r m u l a U n i t s . s i z e ( ) ) ; 
         r e t u r n   f o r m u l a U n i t s [ u n i t I d ] ; 
 } 
 
 c o n s t   A g e n t V a l u e F o r m u l a : : F o r m u l a U n i t &   A g e n t V a l u e F o r m u l a : : G e t F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d )   c o n s t 
 { 
         a s s e r t ( u n i t I d   ! =   N O _ F O R M U L A _ U N I T _ I D ) ; 
         a s s e r t ( u n i t I d   <   f o r m u l a U n i t s . s i z e ( ) ) ; 
         r e t u r n   f o r m u l a U n i t s [ u n i t I d ] ; 
 } 
 
 b o o l   A g e n t V a l u e F o r m u l a : : F o r m u l a U n i t : : C o m p l e t e d A l l C a l c u l a t i o n ( )   c o n s t 
 { 
         i f   ( o p e r a t i o n   > =   F O R M U L A _ O P E R A T I O N _ D I S T R I B U T I O N _ S T A R T )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   v a l u e s . s i z e ( ) ;   i + + )   { 
                 i f   ( v a l u e s [ i ] . f i r s t   ! =   N O _ F O R M U L A _ U N I T _ I D )   { 
                         r e t u r n   f a l s e ; 
                 } 
         } 
 
         r e t u r n   t r u e ; 
 } 
 
 S i m T i m e   A g e n t V a l u e F o r m u l a : : C a l c u l a t e T i m e ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
         c o n s t   b o o l   c a l c u l a t e M a x V a l u e )   c o n s t 
 { 
         i f   ( ( * t h i s ) . I s N u l l ( ) )   { 
                 i f   ( c a l c u l a t e M a x V a l u e )   { 
                         r e t u r n   I N F I N I T E _ T I M E ; 
                 } 
                 r e t u r n   r e s o u r c e . C u r r e n t T i m e ( ) ; 
         } 
 
         r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r a n d G e n ,   c a l c u l a t e M a x V a l u e )   *   S E C O N D ) ; 
 } 
 
 d o u b l e   A g e n t V a l u e F o r m u l a : : C a l c u l a t e D o u b l e ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
         c o n s t   b o o l   c a l c u l a t e M a x V a l u e )   c o n s t 
 { 
         i f   ( ( * t h i s ) . I s N u l l ( ) )   { 
                 r e t u r n   d e f a u l t V a l u e ; 
         } 
 
         r e t u r n   ( * t h i s ) . C a l c u l a t e ( 0 ,   r e s o u r c e ,   r a n d G e n ,   c a l c u l a t e M a x V a l u e ) ; 
 } 
 
 d o u b l e   A g e n t V a l u e F o r m u l a : : C a l c u l a t e U t i l i t y ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
         c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
         c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t 
 { 
         i f   ( ( * t h i s ) . I s N u l l ( ) )   { 
                 r e t u r n   d e f a u l t V a l u e ; 
         } 
 
         r e t u r n   ( * t h i s ) . C a l c u l a t e U t i l i t y ( 0 ,   r e s o u r c e ,   r a n d G e n ,   h e a l t h O r U t i l i t y F a c t o r ,   c o s t ) ; 
 } 
 
 d o u b l e   A g e n t V a l u e F o r m u l a : : C a l c u l a t e ( 
         c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d , 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
         c o n s t   b o o l   c a l c u l a t e M a x V a l u e )   c o n s t 
 { 
         a s s e r t ( u n i t I d   <   f o r m u l a U n i t s . s i z e ( ) ) ; 
         a s s e r t ( u n i t I d   ! =   N O _ F O R M U L A _ U N I T _ I D ) ; 
 
         c o n s t   F o r m u l a U n i t &   f o r m u l a U n i t   =   ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) ; 
         c o n s t   v e c t o r < p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e >   > &   v a l u e s   =   f o r m u l a U n i t . v a l u e s ; 
 
         v e c t o r < d o u b l e >   d o u b l e V a l u e s ( v a l u e s . s i z e ( ) ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   v a l u e s . s i z e ( ) ;   i + + )   { 
                 c o n s t   p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e > &   v a l u e   =   v a l u e s [ i ] ; 
                 i f   ( v a l u e . f i r s t   = =   N O _ F O R M U L A _ U N I T _ I D )   { 
                         d o u b l e V a l u e s [ i ]   =   v a l u e . s e c o n d ; 
                 }   e l s e   { 
                         a s s e r t ( u n i t I d   ! =   v a l u e . f i r s t ) ; 
                         d o u b l e V a l u e s [ i ]   =   ( * t h i s ) . C a l c u l a t e ( v a l u e . f i r s t ,   r e s o u r c e ,   r a n d G e n ,   c a l c u l a t e M a x V a l u e ) ; 
                 } 
         } 
 
         i f   ( I s A g e n t S t a t u s ( f o r m u l a U n i t . o p e r a t i o n ) )   { 
                 r e t u r n   r e s o u r c e . V a l u e ( C o n v e r t T o f A g e n t S t a t u s I d ( f o r m u l a U n i t . o p e r a t i o n ) ) ; 
         } 
 
         i f   ( c a l c u l a t e M a x V a l u e )   { 
                 i f   ( f o r m u l a U n i t . o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ U N I   | | 
                         f o r m u l a U n i t . o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ U N I D )   { 
                         r e t u r n   s t d : : m a x ( d o u b l e V a l u e s [ 0 ] ,   d o u b l e V a l u e s [ 1 ] ) ; 
                 }   e l s e   i f   ( f o r m u l a U n i t . o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ N O R M A L )   { 
                         r e t u r n   d o u b l e V a l u e s [ 1 ]   *   6 . 0   +   d o u b l e V a l u e s [ 0 ] ; 
                 }   e l s e   i f   ( f o r m u l a U n i t . o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ E X P _ D I S T R I B U T I O N   | | 
                                       f o r m u l a U n i t . o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ P O I S S O N   | | 
                                       f o r m u l a U n i t . o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ E R L A N G )   { 
                         r e t u r n   D B L _ M A X ; 
                 } 
         } 
 
         i f   ( f o r m u l a U n i t . o p e r a t i o n   > =   N U M B E R _ F O R M U L A _ T Y P E S )   { 
                 c e r r   < <   " E r r o r :   P r e d e f i n e d   r e s e r v e d   p a r a m e t e r   i s   a v a i l a b l e   o n l y   i n   U t i l i t y F u n c t i o n / R o u t e P r i o r i t y "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         r e t u r n   ( * f o r m u l a P t r s [ f o r m u l a U n i t . o p e r a t i o n ] ) ( d o u b l e V a l u e s ,   r e s o u r c e ,   r a n d G e n ) ; 
 } 
 
 d o u b l e   A g e n t V a l u e F o r m u l a : : C a l c u l a t e U t i l i t y ( 
         c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d , 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
         c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
         c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t 
 { 
         a s s e r t ( u n i t I d   <   f o r m u l a U n i t s . s i z e ( ) ) ; 
         a s s e r t ( u n i t I d   ! =   N O _ F O R M U L A _ U N I T _ I D ) ; 
 
         c o n s t   F o r m u l a U n i t &   f o r m u l a U n i t   =   ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) ; 
         c o n s t   v e c t o r < p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e >   > &   v a l u e s   =   f o r m u l a U n i t . v a l u e s ; 
 
         v e c t o r < d o u b l e >   d o u b l e V a l u e s ( v a l u e s . s i z e ( ) ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   v a l u e s . s i z e ( ) ;   i + + )   { 
                 c o n s t   p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e > &   v a l u e   =   v a l u e s [ i ] ; 
                 i f   ( v a l u e . f i r s t   = =   N O _ F O R M U L A _ U N I T _ I D )   { 
                         d o u b l e V a l u e s [ i ]   =   v a l u e . s e c o n d ; 
                 }   e l s e   { 
                         a s s e r t ( u n i t I d   ! =   v a l u e . f i r s t ) ; 
                         d o u b l e V a l u e s [ i ]   =   ( * t h i s ) . C a l c u l a t e U t i l i t y ( v a l u e . f i r s t ,   r e s o u r c e ,   r a n d G e n ,   h e a l t h O r U t i l i t y F a c t o r ,   c o s t ) ; 
                 } 
         } 
 
         i f   ( I s R o u t e C o s t ( f o r m u l a U n i t . o p e r a t i o n ) )   { 
                 r e t u r n   c o s t . v a l u e s [ C o n v e r t T o R o u t e C o s t I d ( f o r m u l a U n i t . o p e r a t i o n ) ] ; 
         } 
 
         i f   ( I s H e a l t h O r U t i l i t y C o s t ( f o r m u l a U n i t . o p e r a t i o n ) )   { 
                 r e t u r n   h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ 
                         C o n v e r t T o H e a l t h O r U t i l i t y F a c t o r I d ( f o r m u l a U n i t . o p e r a t i o n ) ] ; 
         } 
 
         i f   ( I s A g e n t S t a t u s ( f o r m u l a U n i t . o p e r a t i o n ) )   { 
                 r e t u r n   r e s o u r c e . V a l u e ( C o n v e r t T o f A g e n t S t a t u s I d ( f o r m u l a U n i t . o p e r a t i o n ) ) ; 
         } 
 
         a s s e r t ( f o r m u l a U n i t . o p e r a t i o n   <   N U M B E R _ F O R M U L A _ T Y P E S ) ; 
         r e t u r n   ( * f o r m u l a P t r s [ f o r m u l a U n i t . o p e r a t i o n ] ) ( d o u b l e V a l u e s ,   r e s o u r c e ,   r a n d G e n ) ; 
 } 
 
 v o i d   A g e n t V a l u e F o r m u l a : : R e s o l v e O p e r a t i o n ( 
         c o n s t   s t r i n g &   a S t r i n g , 
         s t r i n g &   l e f t V a l u e , 
         s t r i n g &   r i g h t V a l u e , 
         F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n ) 
 { 
         a s s e r t ( ! a S t r i n g . e m p t y ( ) ) ; 
 
         c o n s t   s t r i n g   n o n s p a c e d S t r i n g   =   N o n s p a c e d R a w F o r m u l a S t r i n g ( a S t r i n g ) ;   / / r e m o v e   o u t m o s t   " ( ) " 
 
         a s s e r t ( ! I s F u n c t i o n S t r i n g ( n o n s p a c e d S t r i n g ) ) ; 
         i n t   c u r r e n t P o s ; 
 
         i n t   n u m b e r R e m a i n i n g F i r s t A r c s   =   0 ; 
 
         b o o l   f o u n d   =   f a l s e ; 
         f o r ( c u r r e n t P o s   =   ( i n t ) ( n o n s p a c e d S t r i n g . s i z e ( )   -   1 ) ;   c u r r e n t P o s   > =   0 ;   c u r r e n t P o s - - )   { 
                 c o n s t   c h a r   a C h a r   =   n o n s p a c e d S t r i n g [ c u r r e n t P o s ] ; 
 
                 i f   ( a C h a r   = =   ' ( ' )   { 
                         n u m b e r R e m a i n i n g F i r s t A r c s - - ; 
                 }   e l s e     i f   ( a C h a r   = =   ' ) ' )   { 
                         n u m b e r R e m a i n i n g F i r s t A r c s + + ; 
                 } 
 
                 i f   ( n u m b e r R e m a i n i n g F i r s t A r c s   = =   0   & & 
                         ( ( a C h a r   = =   ' + ' )     | |   ( a C h a r   = =   ' - ' ) ) )   { 
 
                         i f   ( c u r r e n t P o s   = =   0   | | 
                                 ( c u r r e n t P o s   >   0   & &   n o n s p a c e d S t r i n g [ c u r r e n t P o s   -   1 ]   ! =   ' e ' ) )   { 
                                 f o u n d     =   t r u e ; 
                         } 
                         b r e a k ; 
                 } 
         } 
 
         i f   ( ! f o u n d )   { 
                 f o r ( c u r r e n t P o s   =   ( i n t ) ( n o n s p a c e d S t r i n g . s i z e ( )   -   1 ) ;   c u r r e n t P o s   > =   0 ;   c u r r e n t P o s - - )   { 
                         c o n s t   c h a r   a C h a r   =   n o n s p a c e d S t r i n g [ c u r r e n t P o s ] ; 
 
                         i f   ( a C h a r   = =   ' ( ' )   { 
                                 n u m b e r R e m a i n i n g F i r s t A r c s - - ; 
                         }   e l s e     i f   ( a C h a r   = =   ' ) ' )   { 
                                 n u m b e r R e m a i n i n g F i r s t A r c s + + ; 
                         } 
 
                         i f   ( n u m b e r R e m a i n i n g F i r s t A r c s   = =   0   & & 
                                 ( ( a C h a r   = =   ' / ' )   | |   ( a C h a r   = =   ' * ' )   | |   ( a C h a r   = =   ' % ' )   | |   ( a C h a r   = =   ' ^ ' )   | |   ( a C h a r   = =   ' + ' )   | |   ( a C h a r   = =   ' - ' ) ) )   { 
                                 b r e a k ; 
                         } 
                 } 
         } 
 
         i f   ( c u r r e n t P o s   <   0 )   { / / > =   i n t ( n o n s p a c e d S t r i n g . s i z e ( ) ) )   { 
                 l e f t V a l u e   =   a S t r i n g ; 
                 o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ N O N E ; 
                 r e t u r n ; 
         } 
 
         l e f t V a l u e   =   n o n s p a c e d S t r i n g . s u b s t r ( 0 ,   c u r r e n t P o s ) ; 
 
         a s s e r t ( c u r r e n t P o s   <   i n t ( n o n s p a c e d S t r i n g . s i z e ( ) ) ) ; 
 
         c o n s t   c h a r   a C h a r   =   n o n s p a c e d S t r i n g [ c u r r e n t P o s ] ; 
 
         i f   ( a C h a r   = =   ' + ' )   { 
 
                 i f   ( c u r r e n t P o s   >   0   & &   n o n s p a c e d S t r i n g [ c u r r e n t P o s   -   1 ]   = =   ' e ' )   { 
 
                         o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ E _ P L U S ; 
                         l e f t V a l u e   =   n o n s p a c e d S t r i n g . s u b s t r ( 0 ,   c u r r e n t P o s   -   1 ) ; 
 
                 }   e l s e   { 
                         o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ P L U S ; 
                 } 
 
         }   e l s e   i f   ( a C h a r   = =   ' - ' )   { 
 
                 i f   ( c u r r e n t P o s   >   0   & &   n o n s p a c e d S t r i n g [ c u r r e n t P o s   -   1 ]   = =   ' e ' )   { 
 
                         o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ E _ M I N U S ; 
                         l e f t V a l u e   =   n o n s p a c e d S t r i n g . s u b s t r ( 0 ,   c u r r e n t P o s   -   1 ) ; 
 
                 }   e l s e   { 
                         o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ M I N U S ; 
                 } 
 
         }   e l s e   i f   ( a C h a r   = =   ' / ' )   { 
                 o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ D I V ; 
         }   e l s e   i f   ( a C h a r   = =   ' * ' )   { 
                 o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ M U L T I ; 
         }   e l s e   i f   ( a C h a r   = =   ' % ' )   { 
                 o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ M O D ; 
         }   e l s e   i f   ( a C h a r   = =   ' ^ ' )   { 
                 o p e r a t i o n   =   F O R M U L A _ O P E R A T I O N _ P O W ; 
         }   e l s e   { 
                 c e r r   < <   " E r r o r :   i n v a l i d   o p e r a t i o n   ' "   < <   a C h a r   < <   " '   a t   "   < <   a S t r i n g   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         r i g h t V a l u e   =   n o n s p a c e d S t r i n g . s u b s t r ( c u r r e n t P o s   +   1 ) ; 
 } 
 
 A g e n t V a l u e F o r m u l a : : F o r m u l a U n i t I d T y p e   A g e n t V a l u e F o r m u l a : : A d d F o r m u l a U n i t R e c u r s i v e l y ( 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
         c o n s t   d o u b l e   s i m S t a r t T i m e S e c , 
         c o n s t   s t r i n g &   a S t r i n g , 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   c h a r a c t o r I d s ) 
 { 
         c o n s t   s t r i n g   n o n s p a c e d S t r i n g   =   N o n s p a c e d R a w F o r m u l a S t r i n g ( a S t r i n g ) ; 
 
         i f   ( I s V a r i a b l e S t r i n g ( n o n s p a c e d S t r i n g ) )   { 
 
                 r e t u r n   ( * t h i s ) . A d d V a r i a b l e U n i t ( p a r a m e t e r s ,   n o n s p a c e d S t r i n g ) ; 
 
         }   e l s e   i f   ( I s F u n c t i o n S t r i n g ( n o n s p a c e d S t r i n g ) )   { 
 
                 r e t u r n   ( * t h i s ) . A d d F u n c t i o n U n i t R e c u r s i v e l y ( 
                         p a r a m e t e r s ,   s i m S t a r t T i m e S e c ,   n o n s p a c e d S t r i n g ,   c h a r a c t o r I d s ) ; 
 
         }   e l s e   { 
 
                 c o n s t   F o r m u l a U n i t I d T y p e   u n i t I d   =   f o r m u l a U n i t s . s i z e ( ) ; 
                 f o r m u l a U n i t s . p u s h _ b a c k ( F o r m u l a U n i t ( u n i t I d ) ) ; 
 
                 s t r i n g   l e f t V a l u e ; 
                 s t r i n g   r i g h t V a l u e ; 
 
                 F o r m u l a O p e r a t i o n T y p e   o p e r a t i o n ; 
 
                 ( * t h i s ) . R e s o l v e O p e r a t i o n ( n o n s p a c e d S t r i n g ,   l e f t V a l u e ,   r i g h t V a l u e ,   o p e r a t i o n ) ; 
 
                 ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) . o p e r a t i o n   =   o p e r a t i o n ; 
 
                 a s s e r t ( o p e r a t i o n   <   N U M B E R _ F O R M U L A _ T Y P E S ) ; 
 
                 i f   ( o p e r a t i o n   = =   F O R M U L A _ O P E R A T I O N _ N O N E )   { 
                         b o o l   s u c c e s s ; 
                         d o u b l e   a V a l u e ; 
 
                         i f   ( a S t r i n g . f i n d ( " : " )   ! =   s t r i n g : : n p o s )   { 
                                 d o u b l e   t i m e S e c ; 
                                 C o n v e r t T i m e S t r i n g T o D o u b l e S e c ( a S t r i n g ,   t i m e S e c ,   s u c c e s s ) ; 
 
                                 i f   ( t i m e S e c   <   s i m S t a r t T i m e S e c )   { 
                                         c e r r   < <   " E r r o r :   i n v a l i d   t i m e "   < <   a S t r i n g   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
                                 a V a l u e   =   t i m e S e c   -   s i m S t a r t T i m e S e c ; 
                         }   e l s e   { 
                                 C o n v e r t S t r i n g T o D o u b l e ( a S t r i n g ,   a V a l u e ,   s u c c e s s ) ; 
                         } 
 
                         / /   S t a t i c   c a s t   w o r k a r o u n d   o n   L i n u x   f o r   M i c r o s o f t   v i o l a t i o n   o f   C + +   s t a n d a r d . 
 
                         ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) . v a l u e s . p u s h _ b a c k ( 
                                 m a k e _ p a i r ( s t a t i c _ c a s t < F o r m u l a U n i t I d T y p e > ( N O _ F O R M U L A _ U N I T _ I D ) ,   a V a l u e ) ) ; 
                 }   e l s e   { 
                         F o r m u l a U n i t I d T y p e   l e f t U n i t I d   =   N O _ F O R M U L A _ U N I T _ I D ; 
                         d o u b l e   n o V a l u e   =   0 ; 
 
                         i f   ( ! l e f t V a l u e . e m p t y ( ) )   { 
                                 l e f t U n i t I d   = 
                                         ( * t h i s ) . A d d F o r m u l a U n i t R e c u r s i v e l y ( 
                                                 p a r a m e t e r s ,   s i m S t a r t T i m e S e c ,   l e f t V a l u e ,   c h a r a c t o r I d s ) ; 
                         } 
 
                         c o n s t   F o r m u l a U n i t I d T y p e   r i g h t U n i t I d   = 
                                 ( * t h i s ) . A d d F o r m u l a U n i t R e c u r s i v e l y ( 
                                         p a r a m e t e r s ,   s i m S t a r t T i m e S e c ,   r i g h t V a l u e ,   c h a r a c t o r I d s ) ; 
 
                         a s s e r t ( u n i t I d   ! =   l e f t U n i t I d ) ; 
                         a s s e r t ( u n i t I d   ! =   r i g h t U n i t I d ) ; 
 
                         ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) . v a l u e s . p u s h _ b a c k ( m a k e _ p a i r ( l e f t U n i t I d ,   n o V a l u e ) ) ; 
                         ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) . v a l u e s . p u s h _ b a c k ( m a k e _ p a i r ( r i g h t U n i t I d ,   n o V a l u e ) ) ; 
                 } 
 
                 r e t u r n   u n i t I d ; 
         } 
 } 
 
 A g e n t V a l u e F o r m u l a : : F o r m u l a O p e r a t i o n T y p e   A g e n t V a l u e F o r m u l a : : G e t F o r m u l a O p e r a t i o n ( 
         c o n s t   s t r i n g &   f u n c t i o n S t r i n g , 
         c o n s t   s i z e _ t   n u m b e r A r g u m e n t s )   c o n s t 
 { 
         i f   ( n u m b e r A r g u m e n t s   <   1 )   { 
                 c e r r   < <   " E r r o r :   F u n c t i o n   d e f i n i t i o n   n e e d s   o n e   o r   m o r e   a r g u m e n t s "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         i f   ( f u n c t i o n S t r i n g   = =   " l o g 1 0 " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ L O G 1 0 ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " l o g n "   | | 
                               f u n c t i o n S t r i n g   = =   " l o g "   | | 
                               f u n c t i o n S t r i n g   = =   " l o g a r i t h m " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ L O G N ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " p o w "   | |   f u n c t i o n S t r i n g   = =   " p o w e r " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ P O W ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " m i n "   | |   f u n c t i o n S t r i n g   = =   " m i n i m u m " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ M I N ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " m a x "   | |   f u n c t i o n S t r i n g   = =   " m a x i m u m " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ M A X ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " s q r t "   | |   f u n c t i o n S t r i n g   = =   " s q u a r e r o o t " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ S Q R T ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " s i n "   | |   f u n c t i o n S t r i n g   = =   " s i n e " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ S I N ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " c o s "   | |   f u n c t i o n S t r i n g   = =   " c o s i n e " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ C O S ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " t a n "   | |   f u n c t i o n S t r i n g   = =   " t a n g e n t " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ T A N ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " a b s "   | |   f u n c t i o n S t r i n g   = =   " a b s o l u t e " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ A B S ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " c e i l "   | |   f u n c t i o n S t r i n g   = =   " c e i l i n g " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ C E I L ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " f l o o r " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ F L O O R ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " p i " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ P I ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " e x p "   | |   f u n c t i o n S t r i n g   = =   " e x p o n e n t i a l " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ E X P ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " u n i "   | |   f u n c t i o n S t r i n g   = =   " u n i f o r m " )   { 
                 i f   ( n u m b e r A r g u m e n t s   <   2 )   { 
                         c e r r   < <   " E r r o r :   U n i f o r m   d i s t r i b u t i o n   n e e d s   2   a r g u m e n t s   ( m i n ,   m a x ) . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ U N I ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " u n i d "   | |   f u n c t i o n S t r i n g   = =   " u n i f o r m d " )   { 
                 i f   ( n u m b e r A r g u m e n t s   <   2 )   { 
                         c e r r   < <   " E r r o r :   U n i f o r m   d i s t r i b u t i o n   n e e d s   2   a r g u m e n t s   ( m i n ,   m a x ) . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ U N I D ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " n o r m a l " )   { 
                 i f   ( n u m b e r A r g u m e n t s   <   2 )   { 
                         c e r r   < <   " E r r o r :   E a r l n a g   d i s t r i b u t i o n   n e e d s   2   a r g u m e n t s   ( a v e r a g e ,   d e v i a t i o n ) . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ N O R M A L ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " e x p d i s t "   | |   f u n c t i o n S t r i n g   = =   " e x p o n e n t i a l d i s t r i b u t i o n " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ E X P _ D I S T R I B U T I O N ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " p o i s s o n " )   { 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ P O I S S O N ; 
         }   e l s e   i f   ( f u n c t i o n S t r i n g   = =   " e r l a n g " )   { 
                 i f   ( n u m b e r A r g u m e n t s   <   2 )   { 
                         c e r r   < <   " E r r o r :   E a r l n a g   d i s t r i b u t i o n   n e e d s   2   a r g u m e n t s   ( l a m b d a ,   p h a s e ) . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
                 r e t u r n   F O R M U L A _ O P E R A T I O N _ E R L A N G ; 
         } 
 
         r e t u r n   F O R M U L A _ O P E R A T I O N _ N O N E ; 
 } 
 
 A g e n t V a l u e F o r m u l a : : F o r m u l a U n i t I d T y p e   A g e n t V a l u e F o r m u l a : : A d d V a r i a b l e U n i t ( 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
         c o n s t   s t r i n g &   v a r i a b l e S t r i n g ) 
 { 
         A g e n t V a l u e F o r m u l a : : F o r m u l a O p e r a t i o n T y p e   o p e r a t i o n ; 
 
         i f   ( v a r i a b l e S t r i n g   = =   " _ m o v e b y p r e f e r e d m o b i l i t y m e a n s " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ M O D E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ a r r i v a l t i m e " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ A R R I V A L _ T I M E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ t o t a l t r a v e l t i m e " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ T R A V E L _ T I M E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ t o t a l t r a v e l d i s t a n c e " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ T R A V E L _ D I S T A N C E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ t o t a l p u b l i c t r a n s p o r t a t i o n d e l a y " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ V A R I A B I L I T Y _ T I M E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ p r i c e " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ P R I C E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ t o t a l t r a n s f e r c o u n t " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ T R A N S F E R _ T I M E ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ t o t a l t r a n s f e r d u r a t i o n " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ T R A N S F E R _ D U R A T I O N ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ n u m b e r o f p e o p l e o n r o u t e " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ P A S S A N G E R _ C O N G E S T I O N ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ n u m b e r o f v e h i c l e s o n r o u t e " )   { 
 
                 o p e r a t i o n   =   R O U T E _ C O S T _ S T A R T   +   A G E N T _ R O U T E _ C O S T _ V E H I C L E _ C O N G E S T I O N ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ s e g m e n t c o n g e s t i o n " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ H E A L T H _ F A C T O R _ C O N G E S T I O N ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ d e l a y f o r e x p e c t e d a r r i v a l t i m e " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ U T I L I T Y _ F A C T O R _ T R I P _ D E L A Y ; 
                 a s s e r t ( I s H e a l t h O r U t i l i t y C o s t ( o p e r a t i o n ) ) ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ d e l a y f o r s p e c f i e d a r r i v a l t i m e " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ U T I L I T Y _ F A C T O R _ A R R I V A L _ D E L A Y ; 
                 a s s e r t ( I s H e a l t h O r U t i l i t y C o s t ( o p e r a t i o n ) ) ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ d e l a y f o r l a s t v i a p p o i n t " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ U T I L I T Y _ F A C T O R _ L A S T _ D E L A Y ; 
                 a s s e r t ( I s H e a l t h O r U t i l i t y C o s t ( o p e r a t i o n ) ) ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ d e l a y f o r n e x t v i a p o i n t " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ U T I L I T Y _ F A C T O R _ N E X T _ D E L A Y ; 
                 a s s e r t ( I s H e a l t h O r U t i l i t y C o s t ( o p e r a t i o n ) ) ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ u t i l i t y 1 u p d a t e c o u n t " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ U T I L I T Y _ F A C T O R _ U T I L I T Y 1 _ C O U N T E R ; 
                 a s s e r t ( I s H e a l t h O r U t i l i t y C o s t ( o p e r a t i o n ) ) ; 
 
         }   e l s e   i f   ( v a r i a b l e S t r i n g   = =   " _ u t i l i t y 2 u p d a t e c o u n t " )   { 
 
                 o p e r a t i o n   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   A G E N T _ U T I L I T Y _ F A C T O R _ U T I L I T Y 2 _ C O U N T E R ; 
                 a s s e r t ( I s H e a l t h O r U t i l i t y C o s t ( o p e r a t i o n ) ) ; 
 
         }   e l s e   { 
 
                 i f   ( ! p a r a m e t e r s . C o n t a i n s ( v a r i a b l e S t r i n g ) )   { 
                         c e r r   < <   " E r r o r :   i n v a l i d   v a r i a b l e   "   < <   v a r i a b l e S t r i n g   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 o p e r a t i o n   =   C o n v e r t T o f F o r m u l a O p e r a t i o n T y p e ( p a r a m e t e r s . G e t I d ( v a r i a b l e S t r i n g ) ) ; 
                 a s s e r t ( ( I s A g e n t S t a t u s ( o p e r a t i o n ) ) ) ; 
         } 
 
         c o n s t   F o r m u l a U n i t I d T y p e   u n i t I d   =   f o r m u l a U n i t s . s i z e ( ) ; 
         f o r m u l a U n i t s . p u s h _ b a c k ( F o r m u l a U n i t ( u n i t I d ,   o p e r a t i o n ) ) ; 
 
         r e t u r n   u n i t I d ; 
 } 
 
 A g e n t V a l u e F o r m u l a : : F o r m u l a U n i t I d T y p e   A g e n t V a l u e F o r m u l a : : A d d F u n c t i o n U n i t R e c u r s i v e l y ( 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
         c o n s t   d o u b l e   s i m S t a r t T i m e S e c , 
         c o n s t   s t r i n g &   a S t r i n g , 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   c h a r a c t o r I d s ) 
 { 
         a s s e r t ( I s F u n c t i o n S t r i n g ( a S t r i n g ) ) ; 
 
         c o n s t   F o r m u l a U n i t I d T y p e   u n i t I d   =   f o r m u l a U n i t s . s i z e ( ) ; 
         f o r m u l a U n i t s . p u s h _ b a c k ( F o r m u l a U n i t ( u n i t I d ) ) ; 
 
         v e c t o r < s t r i n g >   a r g u m e n t s ; 
         s i z e _ t   a r g u m e n t S t a r t P o s   =   0 ; 
 
         c o n s t   s i z e _ t   a r c P o s   =   a S t r i n g . f i n d _ f i r s t _ o f ( ' ( ' ) ; 
         c o n s t   s t r i n g   f u n c t i o n S t r i n g   =   a S t r i n g . s u b s t r ( 0 ,   a r c P o s ) ; 
 
         a r g u m e n t S t a r t P o s   =   a r c P o s   +   1 ; 
 
         s i z e _ t   c u r r e n t P o s   =   a r c P o s ; 
         i n t   a r c N u m b e r   =   0 ; 
 
         w h i l e   ( a r c N u m b e r   ! =   - 1 )   { 
                 c u r r e n t P o s   =   a S t r i n g . f i n d _ f i r s t _ o f ( " ( ) , " ,   c u r r e n t P o s   +   1 ) ; 
                 a s s e r t ( c u r r e n t P o s   ! =   s t r i n g : : n p o s ) ; 
 
                 i f   ( a S t r i n g [ c u r r e n t P o s ]   = =   ' ( ' )   { 
                         a r c N u m b e r + + ; 
                 }   e l s e   i f   ( a S t r i n g [ c u r r e n t P o s ]   = =   ' ) ' )   { 
                         a r c N u m b e r - - ; 
                 }   e l s e   i f   ( a r c N u m b e r   = =   0   & &   a S t r i n g [ c u r r e n t P o s ]   = =   ' , ' )   { 
                         a r g u m e n t s . p u s h _ b a c k ( 
                                 a S t r i n g . s u b s t r ( a r g u m e n t S t a r t P o s ,   c u r r e n t P o s   -   a r g u m e n t S t a r t P o s ) ) ; 
                         a r g u m e n t S t a r t P o s   =   c u r r e n t P o s   +   1 ; 
                 } 
         } 
 
         a r g u m e n t s . p u s h _ b a c k ( a S t r i n g . s u b s t r ( a r g u m e n t S t a r t P o s ,   a S t r i n g . s i z e ( )   -   a r g u m e n t S t a r t P o s   -   1 ) ) ; 
 
         c o n s t   F o r m u l a O p e r a t i o n T y p e   o p e r a t i o n   =   G e t F o r m u l a O p e r a t i o n ( f u n c t i o n S t r i n g ,   a r g u m e n t s . s i z e ( ) ) ; 
 
         a s s e r t ( o p e r a t i o n   <   N U M B E R _ F O R M U L A _ T Y P E S ) ; 
 
         ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) . o p e r a t i o n   =   o p e r a t i o n ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a r g u m e n t s . s i z e ( ) ;   i + + )   { 
                 c o n s t   s t r i n g &   a r g u m e n t   =   a r g u m e n t s [ i ] ; 
 
                 F o r m u l a U n i t I d T y p e   a r g U n i t I d ; 
                 d o u b l e   s t a t u s V a l u e   =   0 ; 
 
                 a r g U n i t I d   =   ( * t h i s ) . A d d F o r m u l a U n i t R e c u r s i v e l y ( 
                         p a r a m e t e r s ,   s i m S t a r t T i m e S e c ,   a r g u m e n t ,   c h a r a c t o r I d s ) ; 
 
                 a s s e r t ( u n i t I d   ! =   a r g U n i t I d ) ; 
                 ( * t h i s ) . G e t F o r m u l a U n i t ( u n i t I d ) . v a l u e s . p u s h _ b a c k ( m a k e _ p a i r ( a r g U n i t I d ,   s t a t u s V a l u e ) ) ; 
         } 
 
         r e t u r n   u n i t I d ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 s t a t i c   i n l i n e 
 A g e n t L o c a t i o n T y p e   G e t L o c a t i o n T y p e ( c o n s t   s t r i n g &   l o c a t i o n N a m e ) 
 { 
         i f   ( l o c a t i o n N a m e   = =   " r a n d o m b u i l d i n g " )   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ R A N D O M _ B U I L D I N G ; 
 
         }   e l s e   i f   ( l o c a t i o n N a m e   = =   " r a n d o m p a r k " )   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ R A N D O M _ P A R K ; 
 
         }   e l s e   i f   ( l o c a t i o n N a m e   = =   " r a n d o m p o i " )   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ R A N D O M _ P O I ; 
 
         }   e l s e   i f   ( l o c a t i o n N a m e   = =   " r a n d o m i n t e r s e c t i o n " )   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ R A N D O M _ I N T E R S E C T I O N ; 
 
         }   e l s e   i f   ( l o c a t i o n N a m e   = =   " i n i t i a l l o c a t i o n " )   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ H O M E ; 
 
         }   e l s e   i f   ( l o c a t i o n N a m e   = =   " p r e s e n t l o c a t i o n " )   { 
 
                 r e t u r n   A G N E T _ L O C A T I O N _ P O S I T I O N _ F I L E ; 
 
         }   e l s e   i f   ( l o c a t i o n N a m e   = =   " n o n e "   | |   l o c a t i o n N a m e . e m p t y ( ) )   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ N O N E ; 
 
         }   e l s e   { 
 
                 r e t u r n   A G E N T _ L O C A T I O N _ P O I ; 
         } 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   G e t L o c a t i o n s B y I d ( 
         c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
         c o n s t   s t r i n g &   i d S t r i n g , 
         c o n s t   s e t < G i s P o s i t i o n I d T y p e > &   i g n o r e L o c a t i o n I d s , 
         v e c t o r < G i s P o s i t i o n I d T y p e > &   l o c a t i o n C a n d i d a t e t P o s i t i o n I d s ) 
 { 
         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . c l e a r ( ) ; 
 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e >   n o t U s e d ; 
 
         c o n s t   i n t   g i s O b j e c t I d   =   A g e n t V a l u e F o r m u l a ( 
                 L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > ( ) , 
                 0 , 
                 i d S t r i n g , 
                 n o t U s e d ) . C a l c u l a t e I n t ( r e s o u r c e ,   r a n d G e n ) ; 
 
         c o n s t   G i s P o s i t i o n I d T y p e   p o s i t i o n I d   = 
                 t h e G i s S u b s y s t e m . G e t P o s i t i o n I d ( g i s O b j e c t I d ) ; 
 
         i f   ( i g n o r e L o c a t i o n I d s . f i n d ( p o s i t i o n I d )   = =   i g n o r e L o c a t i o n I d s . e n d ( ) )   { 
 
                 i f   ( p o s i t i o n I d . t y p e   = =   G I S _ A R E A )   { 
 
                         t h e G i s S u b s y s t e m . G e t B u i l d i n g P o s i t i o n I d s I n A r e a ( 
                                 p o s i t i o n I d . i d ,   i g n o r e L o c a t i o n I d s ,   l o c a t i o n C a n d i d a t e t P o s i t i o n I d s ) ; 
 
                 }   e l s e   i f   ( p o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G   | | 
                                       p o s i t i o n I d . t y p e   = =   G I S _ P A R K   | | 
                                       p o s i t i o n I d . t y p e   = =   G I S _ P A R K )   { 
 
                         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . p u s h _ b a c k ( p o s i t i o n I d ) ; 
 
                 }   e l s e   { 
                         c e r r   < <   " E r r o r :   l o c a t i o n   i d   M U S T   b e   a   b u i l d i n g ,   p a r k ,   P O I   o r   a r e a   i d .   i d : "   < <   i d S t r i n g   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
         } 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   G e t L o c a t i o n s B y N a m e ( 
         c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
         c o n s t   m a p < s t r i n g ,   v e c t o r < G i s P o s i t i o n I d T y p e >   > &   l o c a t i o n G r o u p s , 
         c o n s t   s t r i n g &   l o c a t i o n N a m e , 
         c o n s t   s e t < G i s P o s i t i o n I d T y p e > &   i g n o r e L o c a t i o n I d s , 
         c o n s t   b o o l   s e a r c h I n t e r s e c t i o n , 
         v e c t o r < G i s P o s i t i o n I d T y p e > &   l o c a t i o n C a n d i d a t e t P o s i t i o n I d s ) 
 { 
         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . c l e a r ( ) ; 
 
         t y p e d e f   m a p < s t r i n g ,   v e c t o r < G i s P o s i t i o n I d T y p e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   l o c a t i o n G r o u p s . f i n d ( l o c a t i o n N a m e ) ; 
 
         i f   ( i t e r   ! =   l o c a t i o n G r o u p s . e n d ( ) )   { 
 
                 c o n s t   v e c t o r < G i s P o s i t i o n I d T y p e > &   p o s i t i o n I d s   =   ( * i t e r ) . s e c o n d ; 
 
                 f o r ( s i z e _ t   i   =   0 ;   i   <   p o s i t i o n I d s . s i z e ( ) ;   i + + )   { 
                         c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d   =   p o s i t i o n I d s [ i ] ; 
 
                         i f   ( i g n o r e L o c a t i o n I d s . f i n d ( p o s i t i o n I d )   = =   i g n o r e L o c a t i o n I d s . e n d ( ) )   { 
 
                                 i f   ( p o s i t i o n I d . t y p e   = =   G I S _ A R E A )   { 
 
                                         v e c t o r < G i s P o s i t i o n I d T y p e >   b u i l d i n g P o s i t i o n I d s ; 
 
                                         t h e G i s S u b s y s t e m . G e t B u i l d i n g P o s i t i o n I d s I n A r e a ( 
                                                 p o s i t i o n I d . i d ,   i g n o r e L o c a t i o n I d s ,   b u i l d i n g P o s i t i o n I d s ) ; 
 
                                         f o r ( s i z e _ t   j   =   0 ;   j   <   b u i l d i n g P o s i t i o n I d s . s i z e ( ) ;   j + + )   { 
                                                 c o n s t   G i s P o s i t i o n I d T y p e &   b u i l d i n g P o s i t i o n I d   =   b u i l d i n g P o s i t i o n I d s [ j ] ; 
 
                                                 i f   ( i g n o r e L o c a t i o n I d s . f i n d ( b u i l d i n g P o s i t i o n I d )   = =   i g n o r e L o c a t i o n I d s . e n d ( ) )   { 
                                                         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . p u s h _ b a c k ( b u i l d i n g P o s i t i o n I d ) ; 
                                                 } 
                                         } 
 
                                 }   e l s e   { 
                                         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . p u s h _ b a c k ( p o s i t i o n I d ) ; 
                                 } 
                         } 
                 } 
 
         }   e l s e   { 
 
                 c o n s t   G i s P o s i t i o n I d T y p e   p o s i t i o n I d   = 
                         t h e G i s S u b s y s t e m . G e t P o s i t i o n ( l o c a t i o n N a m e ) ; 
 
                 i f   ( i g n o r e L o c a t i o n I d s . f i n d ( p o s i t i o n I d )   = =   i g n o r e L o c a t i o n I d s . e n d ( ) )   { 
 
                         i f   ( s e a r c h I n t e r s e c t i o n )   { 
 
                                 i f   ( p o s i t i o n I d . t y p e   = =   G I S _ I N T E R S E C T I O N )   { 
                                         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . p u s h _ b a c k ( p o s i t i o n I d ) ; 
 
                                 }   e l s e   { 
                                         c e r r   < <   " E r r o r :   p a s s   l o c a t i o n   M U S T   b e   a n   i n t e r s e c t i o n   n a m e .   n a m e : "   < <   l o c a t i o n N a m e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                         }   e l s e   { 
 
                                 i f   ( p o s i t i o n I d . t y p e   = =   G I S _ A R E A )   { 
 
                                         t h e G i s S u b s y s t e m . G e t B u i l d i n g P o s i t i o n I d s I n A r e a ( 
                                                 p o s i t i o n I d . i d ,   i g n o r e L o c a t i o n I d s ,   l o c a t i o n C a n d i d a t e t P o s i t i o n I d s ) ; 
 
                                 }   e l s e   i f   ( p o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G   | | 
                                                       p o s i t i o n I d . t y p e   = =   G I S _ P A R K   | | 
                                                       p o s i t i o n I d . t y p e   = =   G I S _ P O I )   { 
 
                                         l o c a t i o n C a n d i d a t e t P o s i t i o n I d s . p u s h _ b a c k ( p o s i t i o n I d ) ; 
 
                                 }   e l s e   { 
                                         c e r r   < <   " E r r o r :   l o c a t i o n   M U S T   b e   a   b u i l d i n g ,   p a r k ,   P O I   o r   a r e a   n a m e .   n a m e : "   < <   l o c a t i o n N a m e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
                         } 
                 } 
         } 
 } 
 
 S i m T i m e   A g e n t T a s k : : G e t S t a r t T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         i f   ( s t a r t T i m e . I s N u l l ( ) )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         r e t u r n   s t a r t T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 } 
 
 b o o l   A g e n t T a s k : : S a t i s f y C o n d i t i o n ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         f o r ( s i z e _ t   i   =   0 ;   i   <   c o n d i t i o n C h e c k e r s . s i z e ( ) ;   i + + )   { 
                 i f   ( ! c o n d i t i o n C h e c k e r s [ i ] . C h e c k ( r e s o u r c e ) )   { 
                         r e t u r n   f a l s e ; 
                 } 
         } 
 
         r e t u r n   t r u e ; 
 } 
 
 v o i d   A g e n t T a s k : : G e t D e s t i n a t i o n I d ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
         c o n s t   b o o l   i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e , 
         G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
         b o o l &   i s M u l t i p l e D e s t i n a t i o n s , 
         A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         b o o l   i s S p e c i f i e d P o s i t i o n ; 
         V e r t e x   n o t U s e d P o s i t i o n ; 
 
         p r o f i l e A n d T a s k T a b l e P t r - > G e t L o c a t i o n I d ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 t h e A g e n t G i s P t r , 
                 d e s t i n a t i o n , 
                 s h a r e d _ p t r < I n o r d e r F i l e C a c h e > ( ) , 
                 i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e , 
                 f a l s e / * s e a r c h I n t e r s e c t i o n * / , 
                 p o s i t i o n I d , 
                 i s M u l t i p l e D e s t i n a t i o n s , 
                 i s S p e c i f i e d P o s i t i o n , 
                 n o t U s e d P o s i t i o n , 
                 r e s o u r c e , 
                 r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ( ) ) ; 
 
         i f   ( i s S p e c i f i e d P o s i t i o n )   { 
                 c e r r   < <   " L o c a t i o n   s p e c i f i c a t i o n   i s   a v a i l a b l e   o n l y   f o r   i n i t i a l i z a t i o n   l o c a t i o n . "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
 } 
 
 v o i d   A g e n t T a s k : : G e t P a s s V e r t e x I d s ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
         d e q u e < V e r t e x I d T y p e > &   p a s s V e r t e x I d s , 
         A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         p a s s V e r t e x I d s . c l e a r ( ) ; 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   p a s s I n t e r s e c t i o n L o c a t i o n I n f o s . s i z e ( ) ;   i + + )   { 
 
                 G i s P o s i t i o n I d T y p e   p o s i t i o n I d ; 
                 b o o l   i s M u l t i p l e D e s t i n a t i o n s ; 
 
                 b o o l   i s S p e c i f i e d P o s i t i o n ; 
                 V e r t e x   n o t U s e d P o s i t i o n ; 
 
                 p r o f i l e A n d T a s k T a b l e P t r - > G e t L o c a t i o n I d ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                         t h e A g e n t G i s P t r , 
                         p a s s I n t e r s e c t i o n L o c a t i o n I n f o s [ i ] , 
                         s h a r e d _ p t r < I n o r d e r F i l e C a c h e > ( ) , 
                         t r u e / * i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e * / , 
                         t r u e / * s e a r c h I n t e r s e c t i o n * / , 
                         p o s i t i o n I d , 
                         i s M u l t i p l e D e s t i n a t i o n s , 
                         i s S p e c i f i e d P o s i t i o n , 
                         n o t U s e d P o s i t i o n , 
                         r e s o u r c e , 
                         r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 
                 i f   ( i s S p e c i f i e d P o s i t i o n )   { 
                         c e r r   < <   " L o c a t i o n   s p e c i f i c a t i o n   i s   a v a i l a b l e   o n l y   f o r   i n i t i a l i z a t i o n   l o c a t i o n . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } / / i f / / 
 
                 i f   ( p o s i t i o n I d . t y p e   ! =   G I S _ I N T E R S E C T I O N )   { 
                         c e r r   < <   " S p e c i f y   v a l i d   i n t e r s e c t i o n   n a m e   f o r   p a s s   i n t e r s e c t i o n   n a m e s "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 p a s s V e r t e x I d s . p u s h _ b a c k ( 
                         s u b s y s t e m . G e t I n t e r s e c t i o n ( p o s i t i o n I d . i d ) . G e t V e r t e x I d ( ) ) ; 
         } 
 } 
 
 v o i d   A g e n t T a s k T a b l e : : G e t I n i t i a l L o c a t i o n I d ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
         c o n s t   s h a r e d _ p t r < I n o r d e r F i l e C a c h e > &   i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
         G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
         b o o l &   i s S p e c i f i e d P o s i t i o n , 
         V e r t e x &   p o s i t i o n , 
         A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t 
 { 
         b o o l   i s M u l t i p l e P o s i t i o n s N o t U s e d ; 
 
         ( * t h i s ) . G e t L o c a t i o n I d ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 t h e A g e n t G i s P t r , 
                 i n i t i a l L o c a t i o n , 
                 i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
                 p o s i t i o n I d , 
                 i s M u l t i p l e P o s i t i o n s N o t U s e d , 
                 i s S p e c i f i e d P o s i t i o n , 
                 p o s i t i o n , 
                 r e s o u r c e , 
                 r a n d G e n ) ; 
 } 
 
 v o i d   A g e n t T a s k T a b l e : : G e t L o c a t i o n I d ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
         c o n s t   L o c a t i o n I n f o &   l o c a t i o n I n f o , 
         c o n s t   s h a r e d _ p t r < I n o r d e r F i l e C a c h e > &   i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
         G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
         b o o l &   i s M u l t i p l e P o s i t i o n s , 
         b o o l &   i s S p e c i f i e d P o s i t i o n , 
         V e r t e x &   p o s i t i o n , 
         A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t 
 { 
         p r o f i l e A n d T a s k T a b l e P t r - > G e t L o c a t i o n I d ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 t h e A g e n t G i s P t r , 
                 l o c a t i o n I n f o , 
                 i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
                 t r u e / * i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e * / , 
                 f a l s e / * s e a r c h I n t e r s e c t i o n * / , 
                 p o s i t i o n I d , 
                 i s M u l t i p l e P o s i t i o n s , 
                 i s S p e c i f i e d P o s i t i o n , 
                 p o s i t i o n , 
                 r e s o u r c e , 
                 r a n d G e n ) ; 
 } 
 
 v o i d   A g e n t P r o f i l e A n d T a s k T a b l e : : G e t L o c a t i o n I d ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
         c o n s t   L o c a t i o n I n f o &   l o c a t i o n I n f o , 
         c o n s t   s h a r e d _ p t r < I n o r d e r F i l e C a c h e > &   i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
         c o n s t   b o o l   i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e , 
         c o n s t   b o o l   s e a r c h I n t e r s e c t i o n , 
         G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
         b o o l &   i s M u l t i p l e P o s i t i o n s , 
         b o o l &   i s S p e c i f i e d P o s i t i o n , 
         V e r t e x &   p o s i t i o n , 
         A g e n t R e s o u r c e &   r e s o u r c e , 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t 
 { 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
         c o n s t   A g e n t L o c a t i o n T y p e   l o c a t i o n T y p e   =   G e t L o c a t i o n T y p e ( l o c a t i o n I n f o . l o c a t i o n N a m e ) ; 
 
         c o n s t   G i s P o s i t i o n I d T y p e   c u r r e n t P o s i t i o n I d   =   r e s o u r c e . G e t C u r r e n t P o s i t i o n I d ( ) ; 
 
         s e t < G i s P o s i t i o n I d T y p e >   i g n o r e d D e s t i n a t i o n I d s   =   r e s o u r c e . U n r e a c h a b l e D e s t i n a t i o n I d s ( ) ; 
 
         i f   ( i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e )   { 
                 i g n o r e d D e s t i n a t i o n I d s . i n s e r t ( c u r r e n t P o s i t i o n I d ) ; 
         } 
 
         i s S p e c i f i e d P o s i t i o n   =   f a l s e ; 
 
         v e c t o r < G i s P o s i t i o n I d T y p e >   l o c a t i o n C a n d i d a t e I d s ; 
 
         i f   ( l o c a t i o n T y p e   = =   A G E N T _ L O C A T I O N _ N O N E )   { 
 
                 l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( c u r r e n t P o s i t i o n I d ) ; 
 
         }   e l s e   i f   ( l o c a t i o n T y p e   = =   A G E N T _ L O C A T I O N _ R A N D O M _ B U I L D I N G )   { 
 
                 b o o l   f o u n d ; 
                 G i s P o s i t i o n I d T y p e   l o c a t i o n I d ; 
 
                 s u b s y s t e m . G e t A R a n d o m P o s i t i o n ( 
                         G I S _ B U I L D I N G , 
                         i g n o r e d D e s t i n a t i o n I d s , 
                         r a n d G e n , 
                         f o u n d , 
                         l o c a t i o n I d ) ; 
 
                 i f   ( f o u n d )   { 
                         l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( l o c a t i o n I d ) ; 
                 }   e l s e   { 
                         c e r r   < <   " T h e r e   i s   n o   b u i l d i n g   f o r   r a n d o m   b u i l d i n g   s p e c i f i c a t i o n . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
         }   e l s e   i f   ( l o c a t i o n T y p e   = =   A G E N T _ L O C A T I O N _ R A N D O M _ P A R K )   { 
 
                 b o o l   f o u n d ; 
                 G i s P o s i t i o n I d T y p e   l o c a t i o n I d ; 
 
                 s u b s y s t e m . G e t A R a n d o m P o s i t i o n ( 
                         G I S _ P A R K , 
                         i g n o r e d D e s t i n a t i o n I d s , 
                         r a n d G e n , 
                         f o u n d , 
                         l o c a t i o n I d ) ; 
 
                 i f   ( f o u n d )   { 
                         l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( l o c a t i o n I d ) ; 
                 }   e l s e   { 
                         c e r r   < <   " T h e r e   i s   n o   p a r k   f o r   r a n d o m   p a r k   s p e c i f i c a t i o n . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
         }   e l s e   i f   ( l o c a t i o n T y p e   = =   A G E N T _ L O C A T I O N _ R A N D O M _ P O I )   { 
 
                 b o o l   f o u n d ; 
                 G i s P o s i t i o n I d T y p e   l o c a t i o n I d ; 
 
                 s u b s y s t e m . G e t A R a n d o m P o s i t i o n ( 
                         G I S _ P O I , 
                         i g n o r e d D e s t i n a t i o n I d s , 
                         r a n d G e n , 
                         f o u n d , 
                         l o c a t i o n I d ) ; 
 
                 i f   ( f o u n d )   { 
                         l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( l o c a t i o n I d ) ; 
                 }   e l s e   { 
                         c e r r   < <   " T h e r e   i s   n o   P O I   f o r   r a n d o m   P O I   s p e c i f i c a t i o n . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
         }   e l s e   i f   ( l o c a t i o n T y p e   = =   A G E N T _ L O C A T I O N _ R A N D O M _ I N T E R S E C T I O N )   { 
 
                 b o o l   f o u n d ; 
                 G i s P o s i t i o n I d T y p e   l o c a t i o n I d ; 
 
                 s u b s y s t e m . G e t A R a n d o m P o s i t i o n ( 
                         G I S _ I N T E R S E C T I O N , 
                         i g n o r e d D e s t i n a t i o n I d s , 
                         r a n d G e n , 
                         f o u n d , 
                         l o c a t i o n I d ) ; 
 
                 i f   ( f o u n d )   { 
                         l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( l o c a t i o n I d ) ; 
                 }   e l s e   { 
                         c e r r   < <   " T h e r e   i s   n o   i n t e r s e c t i o n   f o r   r a n d o m   i n t e r s e c t i o n   s p e c i f i c a t i o n . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
         }   e l s e     i f   ( l o c a t i o n T y p e   = =   A G E N T _ L O C A T I O N _ H O M E )   { 
 
                 c o n s t   G i s P o s i t i o n I d T y p e   h o m e P o s i t i o n I d   =   r e s o u r c e . H o m e P o s i t i o n I d ( ) ; 
 
                 i f   ( h o m e P o s i t i o n I d   = =   G i s P o s i t i o n I d T y p e ( ) )   { 
                         c e r r   < <   " T h e r e   i s   n o   I n i t i a l L o c a t i o n   p o s i t i o n . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( h o m e P o s i t i o n I d ) ; 
 
         }   e l s e     i f   ( l o c a t i o n T y p e   = =   A G N E T _ L O C A T I O N _ P O S I T I O N _ F I L E )   { 
 
                 c o n s t   A g e n t I d T y p e   a g e n t I d   =   r e s o u r c e . A g e n t I d ( ) ; 
                 c o n s t   d o u b l e   d i s t a n c e G r a n u l a r i t y M e t e r s   =   0 ; 
                 c o n s t   s t r i n g   p o s i t i o n F i l e N a m e   = 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( 
                                 " m o b i l i t y - i n i t - p o s i t i o n s - f i l e " , 
                                 a g e n t I d ) ; 
 
                 T r a c e F i l e M o b i l i t y M o d e l   t r a c e M o b i l i t y ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                         a g e n t I d , 
                         n u l l I n s t a n c e I d , 
                         * i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
                         p o s i t i o n F i l e N a m e , 
                         a g e n t I d , 
                         d i s t a n c e G r a n u l a r i t y M e t e r s , 
                         t h e A g e n t G i s P t r - > G e t S u b s y s t e m P t r ( ) ) ; 
 
                 O b j e c t M o b i l i t y P o s i t i o n   i n i t i a l P o s i t i o n ; 
 
                 t r a c e M o b i l i t y . G e t U n a d j u s t e d P o s i t i o n F o r T i m e ( Z E R O _ T I M E ,   i n i t i a l P o s i t i o n ) ; 
 
                 p o s i t i o n   =   V e r t e x ( 
                         i n i t i a l P o s i t i o n . X _ P o s i t i o n M e t e r s ( ) , 
                         i n i t i a l P o s i t i o n . Y _ P o s i t i o n M e t e r s ( ) , 
                         i n i t i a l P o s i t i o n . H e i g h t F r o m G r o u n d M e t e r s ( ) ) ; 
 
                 v e c t o r < G i s O b j e c t T y p e >   i n i t i a l G i s O b j e c t T y p e s ; 
 
                 i n i t i a l G i s O b j e c t T y p e s . p u s h _ b a c k ( G I S _ B U I L D I N G ) ; 
                 i n i t i a l G i s O b j e c t T y p e s . p u s h _ b a c k ( G I S _ P A R K ) ; 
                 i n i t i a l G i s O b j e c t T y p e s . p u s h _ b a c k ( G I S _ P O I ) ; 
 
                 c o n s t   G i s P o s i t i o n I d T y p e   i n i t i a l P o s i t i o n I d   = 
                         s u b s y s t e m . G e t P o s i t i o n I d W i t h Z V a l u e ( 
                                 p o s i t i o n , 
                                 i n i t i a l G i s O b j e c t T y p e s ) ; 
 
                 i f   ( ! i n i t i a l P o s i t i o n I d . I s V a l i d ( ) )   { 
                         c e r r   < <   " T h e r e   i s   n o   G I S   o b j e c t   f o r   i n i t i a l i z a t i o n .   ( "   < <   p o s i t i o n . x   < <   " , "   < <   p o s i t i o n . y   < <   " )   a g e n t   "   < <   a g e n t I d   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( i n i t i a l P o s i t i o n I d ) ; 
                 i s S p e c i f i e d P o s i t i o n   =   t r u e ; 
 
         }   e l s e   { 
 
                 i f   ( l o c a t i o n I n f o . i s I d )   { 
 
                         G e t L o c a t i o n s B y I d ( 
                                 s u b s y s t e m , 
                                 r e s o u r c e , 
                                 r a n d G e n , 
                                 l o c a t i o n I n f o . l o c a t i o n N a m e , 
                                 i g n o r e d D e s t i n a t i o n I d s , 
                                 l o c a t i o n C a n d i d a t e I d s ) ; 
 
                 }   e l s e   { 
 
                         i f   ( t h e P u b l i c V e h i c l e T a b l e P t r - > C o n t a i n s L i n e ( l o c a t i o n I n f o . l o c a t i o n N a m e ) )   { 
                                 l o c a t i o n C a n d i d a t e I d s . p u s h _ b a c k ( 
                                         G i s P o s i t i o n I d T y p e ( 
                                                 G I S _ V E H I C L E _ L I N E , 
                                                 t h e P u b l i c V e h i c l e T a b l e P t r - > G e t L i n e I d ( l o c a t i o n I n f o . l o c a t i o n N a m e ) ) ) ; 
                         }   e l s e   { 
 
                                 G e t L o c a t i o n s B y N a m e ( 
                                         s u b s y s t e m , 
                                         l o c a t i o n G r o u p s , 
                                         l o c a t i o n I n f o . l o c a t i o n N a m e , 
                                         i g n o r e d D e s t i n a t i o n I d s , 
                                         s e a r c h I n t e r s e c t i o n , 
                                         l o c a t i o n C a n d i d a t e I d s ) ; 
                         } 
                 } 
         } 
 
         i f   ( l o c a t i o n C a n d i d a t e I d s . e m p t y ( ) )   { 
                 p o s i t i o n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
                 i s M u l t i p l e P o s i t i o n s   =   f a l s e ; 
                 r e t u r n ; 
         } 
 
         i f   ( l o c a t i o n C a n d i d a t e I d s . s i z e ( )   = =   1 )   { 
                 i f   ( i g n o r e d D e s t i n a t i o n I d s . f i n d ( l o c a t i o n C a n d i d a t e I d s . f r o n t ( ) )   ! =   i g n o r e d D e s t i n a t i o n I d s . e n d ( ) )   { 
                         p o s i t i o n I d   =   U N R E A C H A B L E _ P O S I T I O N _ I D ; 
                 }   e l s e   { 
                         p o s i t i o n I d   =   l o c a t i o n C a n d i d a t e I d s . f r o n t ( ) ; 
                 } 
 
                 i s M u l t i p l e P o s i t i o n s   =   f a l s e ; 
                 r e t u r n ; 
         } 
 
         i s M u l t i p l e P o s i t i o n s   =   t r u e ; 
 
         i f   ( l o c a t i o n I n f o . l o c a t i o n C h o i c e T y p e   = =   A G E N T _ L O C A T I O N _ C H O I C E _ N E A R E S T )   { 
 
                 V e r t e x   b a s e P o s i t i o n ; 
 
                 i f   ( ( l o c a t i o n I n f o . n e a r e s t C h o i c e B a s e L o c a t i o n N a m e . e m p t y ( ) )   | | 
                         ( l o c a t i o n I n f o . n e a r e s t C h o i c e B a s e L o c a t i o n N a m e   = =   " a g e n t l o c a t i o n " ) )   { 
 
                         b a s e P o s i t i o n   =   r e s o u r c e . P o s i t i o n ( ) ; 
                 } 
                 e l s e   { 
 
                         L o c a t i o n I n f o   b a s e L o c a t i o n I n f o ; 
                         G i s P o s i t i o n I d T y p e   b a e s P o s i t i o n I d ; 
                         b o o l   n o t U s e d I s B a s e M u l t i p l e P o s i t i o n s ; 
 
                         ( * t h i s ) . G e t L o c a t i o n I d ( 
                                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                                 t h e A g e n t G i s P t r , 
                                 L o c a t i o n I n f o ( f a l s e / * i s I d * / ,   A G E N T _ L O C A T I O N _ C H O I C E _ R A N D O M ,   l o c a t i o n I n f o . n e a r e s t C h o i c e B a s e L o c a t i o n N a m e ) , 
                                 s h a r e d _ p t r < I n o r d e r F i l e C a c h e > ( ) , 
                                 f a l s e / * i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e * / , 
                                 f a l s e / * s e a r c h I n t e r s e c t i o n * / , 
                                 b a e s P o s i t i o n I d , 
                                 n o t U s e d I s B a s e M u l t i p l e P o s i t i o n s , 
                                 i s S p e c i f i e d P o s i t i o n , 
                                 p o s i t i o n , 
                                 r e s o u r c e , 
                                 r a n d G e n ) ; 
 
                         i f   ( i s S p e c i f i e d P o s i t i o n )   { 
                                 c e r r   < <   " L o c a t i o n   s p e c i f i c a t i o n   i s   a v a i l a b l e   o n l y   f o r   \ " P r e s e n t L i c a t i o n \ " . "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } / / i f / / 
 
                         i f   ( b a e s P o s i t i o n I d . I s V a l i d ( ) )   { 
                                 b a s e P o s i t i o n   =   s u b s y s t e m . G e t P o s i t i o n V e r t e x ( b a e s P o s i t i o n I d ) ; 
                         } 
                         e l s e   { 
                                 b a s e P o s i t i o n   =   r e s o u r c e . P o s i t i o n ( ) ; 
                         } / / i f / / 
 
                 } / / i f / 
 
                 d o u b l e   m i n D i s t a n c e   =   D B L _ M A X ; 
 
                 f o r ( s i z e _ t   i   =   0 ;   i   <   l o c a t i o n C a n d i d a t e I d s . s i z e ( ) ;   i + + )   { 
 
                         c o n s t   V e r t e x   g i s O b j e c t P o s i t i o n   =   s u b s y s t e m . G e t P o s i t i o n V e r t e x ( l o c a t i o n C a n d i d a t e I d s [ i ] ) ; 
 
                         d o u b l e   d i s t a n c e   =   b a s e P o s i t i o n . D i s t a n c e T o ( g i s O b j e c t P o s i t i o n ) ; 
 
                         i f   ( d i s t a n c e   <   m i n D i s t a n c e )   { 
                                 m i n D i s t a n c e   =   d i s t a n c e ; 
                                 p o s i t i o n I d   =   l o c a t i o n C a n d i d a t e I d s [ i ] ; 
                         } 
                 } 
 
                 / / c o u t   < <   t a r a i m a w a s i 
                 / / c o u t   < <   " ( x , y )   =   "   < <   " ( "   < <   s u b s y s t e m . G e t P o s i t i o n V e r t e x ( p o s i t i o n I d ) . x   < <   " , "   < <   s u b s y s t e m . G e t P o s i t i o n V e r t e x ( p o s i t i o n I d ) . y   < <   " )   f o r   A g e n t   "   < <   r e s o u r c e . A g e n t I d ( )   < <   e n d l ; 
 
         }   e l s e   i f   ( l o c a t i o n I n f o . l o c a t i o n C h o i c e T y p e   = =   A G E N T _ L O C A T I O N _ C H O I C E _ R A N D O M )   { 
 
                 p o s i t i o n I d   =   l o c a t i o n C a n d i d a t e I d s [ 
                         r a n d G e n . G e n e r a t e R a n d o m I n t ( 
                                 0 ,   ( i n t 3 2 _ t ) ( l o c a t i o n C a n d i d a t e I d s . s i z e ( )   -   1 ) ) ] ; 
         } 
 } 
 
 S i m T i m e   A g e n t T a s k : : G e t E n d T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         i f   ( e n d T i m e . I s N u l l ( ) )   { 
                 r e t u r n   I N F I N I T E _ T I M E ; 
         } 
 
         r e t u r n   e n d T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 } 
 
 S i m T i m e   A g e n t T a s k : : G e t W a i t T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         i f   ( w a i t T i m e . I s N u l l ( ) )   { 
                 r e t u r n   Z E R O _ T I M E ; 
         } 
 
         r e t u r n   w a i t T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ; 
 } 
 
 v o i d   A g e n t T a s k : : G e t T i m e L i n e ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         c o n s t   S i m T i m e &   e a r l y S t a r t T i m e , 
         T i m e T o S e a r c h R o u t e &   t i m e T o S e a r c h R o u t e )   c o n s t 
 { 
         t i m e T o S e a r c h R o u t e . s p e c i f i e d A r r i v a l T i m e   =   ! a r r i v a l T i m e . I s N u l l ( ) ; 
         t i m e T o S e a r c h R o u t e . s p e c i f i e d D e p a r t u r e T i m e   =   ! d e p a r t u r e T i m e . I s N u l l ( ) ; 
 
         t i m e T o S e a r c h R o u t e . d e p a r t u r e T i m e   =   e a r l y S t a r t T i m e ; 
         t i m e T o S e a r c h R o u t e . e a r l y D e p a r t u r e T i m e   =   e a r l y S t a r t T i m e ; 
         t i m e T o S e a r c h R o u t e . l a t e D e p a r t u r e T i m e   =   I N F I N I T E _ T I M E ; 
 
         i f   ( ! t i m e T o S e a r c h R o u t e . s p e c i f i e d A r r i v a l T i m e   & & 
                 ! t i m e T o S e a r c h R o u t e . s p e c i f i e d D e p a r t u r e T i m e )   { 
 
                 t i m e T o S e a r c h R o u t e . e a r l y A r r i v a l T i m e   =   Z E R O _ T I M E ; 
                 t i m e T o S e a r c h R o u t e . a r r i v a l T i m e   =   I N F I N I T E _ T I M E ; 
                 t i m e T o S e a r c h R o u t e . l a t e A r r i v a l T i m e   =   I N F I N I T E _ T I M E ; 
                 r e t u r n ; 
         } 
 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n   =   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ; 
 
         i f   ( ! a r r i v a l T i m e . I s N u l l ( ) )   { 
                 t i m e T o S e a r c h R o u t e . a r r i v a l T i m e   = 
                         s t d : : m a x ( e a r l y S t a r t T i m e ,   a r r i v a l T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r a n d G e n ) ) ; 
         } 
         i f   ( ! e a r l y A r r i v a l T i m e . I s N u l l ( ) )   { 
                 t i m e T o S e a r c h R o u t e . e a r l y A r r i v a l T i m e   = 
                         s t d : : m a x ( e a r l y S t a r t T i m e ,   e a r l y A r r i v a l T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r a n d G e n ) ) ; 
         } 
         i f   ( ! l a t e A r r i v a l T i m e . I s N u l l ( ) )   { 
                 t i m e T o S e a r c h R o u t e . l a t e A r r i v a l T i m e   = 
                         s t d : : m a x ( e a r l y S t a r t T i m e ,   l a t e A r r i v a l T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r a n d G e n ) ) ; 
         } 
         i f   ( ! d e p a r t u r e T i m e . I s N u l l ( ) )   { 
                 t i m e T o S e a r c h R o u t e . d e p a r t u r e T i m e   = 
                         s t d : : m a x ( e a r l y S t a r t T i m e ,   d e p a r t u r e T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r a n d G e n ) ) ; 
         } 
         i f   ( ! e a r l y D e p a r t u r e T i m e . I s N u l l ( ) )   { 
                 t i m e T o S e a r c h R o u t e . e a r l y D e p a r t u r e T i m e   = 
                         s t d : : m a x ( e a r l y S t a r t T i m e ,   e a r l y D e p a r t u r e T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r a n d G e n ) ) ; 
         } 
         i f   ( ! l a t e D e p a r t u r e T i m e . I s N u l l ( ) )   { 
                 t i m e T o S e a r c h R o u t e . l a t e D e p a r t u r e T i m e   = 
                         s t d : : m a x ( e a r l y S t a r t T i m e ,   l a t e D e p a r t u r e T i m e . C a l c u l a t e T i m e ( r e s o u r c e ,   r a n d G e n ) ) ; 
         } 
 
         t i m e T o S e a r c h R o u t e . e a r l y A r r i v a l T i m e   = 
                 s t d : : m i n ( t i m e T o S e a r c h R o u t e . e a r l y A r r i v a l T i m e ,   t i m e T o S e a r c h R o u t e . a r r i v a l T i m e ) ; 
 
         t i m e T o S e a r c h R o u t e . l a t e A r r i v a l T i m e   = 
                 s t d : : m a x ( t i m e T o S e a r c h R o u t e . l a t e A r r i v a l T i m e ,   t i m e T o S e a r c h R o u t e . a r r i v a l T i m e ) ; 
 
         t i m e T o S e a r c h R o u t e . e a r l y D e p a r t u r e T i m e   = 
                 s t d : : m i n ( t i m e T o S e a r c h R o u t e . e a r l y D e p a r t u r e T i m e ,   t i m e T o S e a r c h R o u t e . d e p a r t u r e T i m e ) ; 
 
         t i m e T o S e a r c h R o u t e . l a t e D e p a r t u r e T i m e   = 
                 s t d : : m a x ( t i m e T o S e a r c h R o u t e . l a t e D e p a r t u r e T i m e ,   t i m e T o S e a r c h R o u t e . d e p a r t u r e T i m e ) ; 
 } 
 
 v o i d   A g e n t T a s k T a b l e : : G e t S t a t u s C h a n g e s ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         p r i o r i t y _ q u e u e _ s t a b l e < A g e n t S t a t u s C h a n g e E v e n t > &   t i m e L i n e S t a t u s C h a n g e E v e n t s )   c o n s t 
 { 
         w h i l e   ( ! t i m e L i n e S t a t u s C h a n g e E v e n t s . e m p t y ( ) )   { 
                 t i m e L i n e S t a t u s C h a n g e E v e n t s . p o p ( ) ; 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   s t a t u s C h a n g e P t r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   A g e n t T a s k &   s t a t u s C h a n g e T a s k   =   * ( s t a t u s C h a n g e P t r s [ i ] ) ; 
                 c o n s t   S i m T i m e   c h a n g e T i m e   =   s t a t u s C h a n g e T a s k . G e t S t a r t T i m e ( r e s o u r c e ) ; 
 
                 t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                         A g e n t S t a t u s C h a n g e E v e n t ( 
                                 c h a n g e T i m e , 
                                 i , 
                                 A G E N T _ S T A T U S _ C H A N G E _ A T _ S P E C I F I C _ T I M E ) ) ; 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   i n t e r r u p t T a s k P t r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   A g e n t T a s k &   s t a t u s C h a n g e T a s k   =   * ( i n t e r r u p t T a s k P t r s [ i ] ) ; 
                 c o n s t   S i m T i m e   c h a n g e T i m e   =   s t a t u s C h a n g e T a s k . G e t S t a r t T i m e ( r e s o u r c e ) ; 
 
                 t i m e L i n e S t a t u s C h a n g e E v e n t s . p u s h ( 
                         A g e n t S t a t u s C h a n g e E v e n t ( 
                                 c h a n g e T i m e , 
                                 i , 
                                 A G E N T _ S T A T U S _ C H A N G E _ T A S K _ I N T E R R U P T I O N _ S T A R T ) ) ; 
         } 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 A g e n t C o n d i t i o n C h e c k e r : : A g e n t C o n d i t i o n C h e c k e r ( 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   i n i t P a r a m e t e r s , 
         c o n s t   C o n d i t i o n P a r a m e t e r T y p e &   i n i t P a r a m e t e r T y p e , 
         c o n s t   d o u b l e   i n i t S i m S t a r t T i m e S e c , 
         c o n s t   s t r i n g &   i n i t S t r i n g , 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   i n i t C h a r a c t o r I d s ) 
         : 
         p a r a m e t e r T y p e ( i n i t P a r a m e t e r T y p e ) 
 { 
         a s s e r t ( i n i t S t r i n g . s i z e ( )   >   2 ) ; 
 
         c o n s t   s t r i n g   c h e c k S t r i n g   =   i n i t S t r i n g . s u b s t r ( 0 ,   2 ) ; 
         s i z e _ t   c h e c k S t r i n g L e n g t h   =   2 ; 
 
         i f   ( c h e c k S t r i n g   = =   " = = " )   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 1 ; 
         }   e l s e   i f   ( c h e c k S t r i n g   = =   " ! = " )   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 2 ; 
         }   e l s e   i f   ( c h e c k S t r i n g   = =   " < = " )   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 4 ; 
         }   e l s e   i f   ( c h e c k S t r i n g   = =   " > = " )   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 6 ; 
         }   e l s e   i f   ( c h e c k S t r i n g [ 0 ]   = =   ' < ' )   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 3 ; 
                 c h e c k S t r i n g L e n g t h   =   1 ; 
         }   e l s e   i f   ( c h e c k S t r i n g [ 0 ]   = =   ' > ' )   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 5 ; 
                 c h e c k S t r i n g L e n g t h   =   1 ; 
         }   e l s e   { 
                 C h e c k e r   =   & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 1 ; 
                 c h e c k S t r i n g L e n g t h   =   0 ; 
         } 
 
         f o r m u l a   =   A g e n t V a l u e F o r m u l a ( 
                 i n i t P a r a m e t e r s , 
                 i n i t S i m S t a r t T i m e S e c , 
                 i n i t S t r i n g . s u b s t r ( c h e c k S t r i n g L e n g t h ) , 
                 i n i t C h a r a c t o r I d s ) ; 
 } 
 
 b o o l   A g e n t C o n d i t i o n C h e c k e r : : C h e c k ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t 
 { 
         i f   ( p a r a m e t e r T y p e   = =   C O N D I T I O N _ P A R A M E T E R _ T I M E )   { 
                 r e t u r n   ( t h i s - > * ( C h e c k e r ) ) ( d o u b l e ( r e s o u r c e . C u r r e n t T i m e ( ) / S E C O N D ) ,   f o r m u l a . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ) ; 
         }   e l s e   { 
                 r e t u r n   ( t h i s - > * ( C h e c k e r ) ) ( r e s o u r c e . V a l u e ( C o n v e r t T o S t a t u s I d ( p a r a m e t e r T y p e ) ) ,   f o r m u l a . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r e s o u r c e . G e t R a n d o m N u m b e r G e n e r a t o r ( ) ) ) ; 
         } 
 } 
 
 A g e n t P r o f i l e : : A g e n t P r o f i l e ( 
         c o n s t   A g e n t P r o f i l e T y p e &   i n i t P r o f i l e T y p e , 
         c o n s t   s t r i n g &   i n i t P r o f i l e N a m e ) 
         : 
         p r o f i l e N a m e ( i n i t P r o f i l e N a m e ) , 
         p r o f i l e T y p e ( i n i t P r o f i l e T y p e ) , 
         u s e r T y p e ( A G E N T _ U S E R _ T Y P E _ N O N E ) , 
         m o b i l i t y C l a s s ( A G E N T _ M O B I L T Y _ C L A S S _ N O R M A L ) , 
         t i c k e t T y p e ( A G E N T _ T I C K E T _ F U L L _ F A R E ) , 
         r o u t e C o s t F o r m u l a s ( N U M B E R _ A G E N T _ B E H A V I O R S ) 
 { 
         f o r ( A g e n t S t a t u s I d T y p e   s t a t u s I d   =   0 ;   s t a t u s I d   <   N U M B E R _ A G E N T _ S T A T U S _ V A L U E S ;   s t a t u s I d + + )   { 
 
                 d o u b l e   d e f a u l t V a l u e   =   0 ; 
 
                 i f   ( A G E N T _ R E S E R V E D _ S T A T U S _ Q U E R Y _ T R I G G E R _ S T A R T   < =   s t a t u s I d   & & 
                         s t a t u s I d   < =   A G E N T _ R E S E R V E D _ S T A T U S _ Q U E R Y _ T R I G G E R _ E N D )   { 
                         d e f a u l t V a l u e   =   D B L _ M A X ; 
                 } 
                 p a r a m e t e r s [ R E S E R V E D _ A G E N T _ S T A T U S _ N A M E S [ s t a t u s I d ] ]   =   A g e n t V a l u e F o r m u l a ( d e f a u l t V a l u e ) ; 
         } 
 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ S E E I N G _ P E D E S T R I A N _ P R O B A B I L I T Y ]   =   D E F A U L T _ S E E I N G _ P E D E S T R I A N _ P R O B A B I L I T Y ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ V E H I C L E _ S P E E D ]   =   D E F A U L T _ M A X _ V E H I C L E _ S P E E D ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ L A N E _ C H A N G E _ A C C E L E R A T I O N _ T H R E S H O L D ]   =   D E F A U L T _ L A N E _ C H A N G E _ A C C E L E R A T I O N _ T H R E S H O L D ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ T I M E _ H E A D W A Y ]   =   D E F A U L T _ T I M E _ H E A D W A Y ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ M I N _ V E H I C L E _ G A P ]   =   D E F A U L T _ M I N _ V E H I C L E _ G A P ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ A C C E L E R A T I O N ]   =   D E F A U L T _ M A X _ A C C E L E R A T I O N ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ D E C E L E R A T I O N ]   =   D E F A U L T _ M A X _ D E C E L E R A T I O N ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ V E L O C I T Y _ R A T I O _ G A P _ D I S T A N C E ]   =   D E F A U L T _ V E L O C I T Y _ R A T I O _ G A P _ D I S T A N C E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ O T H E R _ V E H I C L E _ E N A T R A N C E _ T I M E ]   =   D E F A U L T _ O T H E R _ V E H I C L E _ E N A T R A N C E _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ P A S S I V E _ Y I E L D _ T I M E ]   =   D E F A U L T _ P A S S I V E _ Y I E L D _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ A C T I V E _ Y I E L D _ T I M E ]   =   D E F A U L T _ A C T I V E _ Y I E L D _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ Y I E L D _ W A I T I N G _ T I M E ]   =   D E F A U L T _ Y I E L D _ W A I T I N G _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ A C C E P T A B L E _ W A L K _ D I S T A N C E _ T O _ C A R ]   =   D E F A U L T _ A C C E P T A B L E _ W A L K _ D I S T A N C E _ T O _ V E H I C L E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ A C C E P T A B L E _ W A L K _ D I S T A N C E _ T O _ S T O P ]   =   D E F A U L T _ A C C E P T A B L E _ W A L K _ D I S T A N C E _ T O _ S T O P ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ M I N _ V E H I C L E _ R O U T E _ D I S T A N C E ]   =   D E F A U L T _ M I N _ V E H I C L E _ R O U T E _ D I S T A N C E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ N U M B E R _ M A X _ R O U T E _ C A N D I D A T E S ]   =   D E F A U L T _ N U M B E R _ M A X _ R O U T E _ C A N D I D A T E S ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ N U M B E R _ P E O P L E ]   =   D E F A U L T _ N U M B E R _ P E O P L E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ E N T R A N C E _ W A I T _ T I M E ]   =   D E F A U L T _ E N T R A N C E _ W A I T _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ V E H I C L E _ E N T R A N C E _ W A I T _ T I M E ]   =   D E F A U L T _ V E H I C L E _ E N T R A N C E _ W A I T _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ T A X I C A L L _ W A I T _ T I M E ]   =   D E F A U L T _ T A X I C A L L _ W A I T _ T I M E ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ B R A K I N G _ D E C C E L E R A T I O N ]   =   D E F A U L T _ M A X _ B R A K I N G _ D E C C E L E R A T I O N ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ A C C E L E R A T I O N _ E X P O N E N T ]   =   D E F A U L T _ A C C E L E R A T I O N _ E X P O N E N T ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ S A V E _ D E C E L E R A T I O N ]   =   D E F A U L T _ S A V E _ D E C E L E R A T I O N ; 
         p a r a m e t e r s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ T U R N _ S P E E D ]   =   D E F A U L T _ M A X _ T U R N _ S P E E D ; 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   M a k e S e t O f A l l A g e n t I d s ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         s e t < A g e n t I d T y p e > &   a g e n t I d s ) 
 { 
         s e t < A g e n t I d T y p e >   p r o f i l e A g e n t I d s ; 
         s e t < A g e n t I d T y p e >   b e h a v i o r A g e n t I d s ; 
 
         t h e P a r a m e t e r D a t a b a s e R e a d e r . M a k e S e t O f A l l N o d e I d s W i t h P a r a m e t e r ( " m u l t i a g e n t - p r o f i l e - t y p e " ,   p r o f i l e A g e n t I d s ) ; 
         t h e P a r a m e t e r D a t a b a s e R e a d e r . M a k e S e t O f A l l N o d e I d s W i t h P a r a m e t e r ( " m u l t i a g e n t - b e h a v i o r - t y p e " ,   b e h a v i o r A g e n t I d s ) ; 
 
         a g e n t I d s . i n s e r t ( p r o f i l e A g e n t I d s . b e g i n ( ) ,   p r o f i l e A g e n t I d s . e n d ( ) ) ; 
         a g e n t I d s . i n s e r t ( b e h a v i o r A g e n t I d s . b e g i n ( ) ,   b e h a v i o r A g e n t I d s . e n d ( ) ) ; 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 c o n s t   s t r i n g   A G E N T _ T Y P E _ T A X I ( " t a x i " ) ; 
 c o n s t   s t r i n g   A G E N T _ T Y P E _ B U S ( " b u s " ) ; 
 
 c o n s t   s t r i n g   M u l t i A g e n t S i m u l a t o r : : m o d e l N a m e   =   " M a s " ; 
 
 # p r a g m a   w a r n i n g ( d i s a b l e : 4 3 5 5 ) 
 
 M u l t i A g e n t S i m u l a t o r : : M u l t i A g e n t S i m u l a t o r ( 
         c o n s t   s h a r e d _ p t r < P a r a m e t e r D a t a b a s e R e a d e r > &   i n i t P a r a m e t e r D a t a b a s e R e a d e r P t r , 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e > &   i n i t S i m u l a t i o n E n g i n e P t r , 
         c o n s t   R a n d o m N u m b e r G e n e r a t o r S e e d &   i n i t R u n S e e d , 
         c o n s t   b o o l   i n i t R u n S e q u e n t i a l l y , 
         c o n s t   b o o l   i n i t I s S c e n a r i o S e t t i n g O u t p u t M o d e , 
         c o n s t   s t r i n g &   i n i t I n p u t C o n f i g F i l e N a m e , 
         c o n s t   s t r i n g &   i n i t O u t p u t C o n f i g F i l e N a m e ) 
         : 
         N e t w o r k S i m u l a t o r ( 
                 i n i t P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                 i n i t S i m u l a t i o n E n g i n e P t r , 
                 i n i t R u n S e e d , 
                 i n i t R u n S e q u e n t i a l l y ) , 
         c u r r e n t S n a p s h o t I d ( 0 ) , 
         c u r r e n t T i m e ( Z E R O _ T I M E ) , 
         t i m e S t e p ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d T i m e ( 
                         " t i m e - s t e p - e v e n t - s y n c h r o n i z a t i o n - s t e p " ) ) , 
         i s S i m u l a t i o n D o n e ( f a l s e ) , 
         i s S c e n a r i o S e t t i n g O u t p u t M o d e ( i n i t I s S c e n a r i o S e t t i n g O u t p u t M o d e ) , 
         i n p u t C o n f i g F i l e N a m e ( i n i t I n p u t C o n f i g F i l e N a m e ) , 
         o u t p u t C o n f i g F i l e N a m e ( i n i t O u t p u t C o n f i g F i l e N a m e ) , 
         p r o f i l e V a l u e O u t p u t S u b s y s t e m ( * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ) , 
         r e s e r v e d V e h i c l e N o d e P t r s ( N U M B E R _ V E H I C L E _ T Y P E S ) , 
         m a s t e r A n y A g e n t P t r ( 
                 A g e n t : : C r e a t e M a s t e r A g e n t ( 
                         t h i s , 
                         M A S T E R _ A N Y _ A G E N T _ I D , 
                         s h a r e d _ p t r < A g e n t P r o f i l e > ( n e w   A g e n t P r o f i l e ( I N V A L I D _ A G E N T _ T Y P E ) ) , 
                         s h a r e d _ p t r < A g e n t T a s k T a b l e > ( n e w   A g e n t T a s k T a b l e ( n u l l p t r ) ) ) ) , 
         t h e S i m u l a t i o n R u n I n t e r f a c e P t r ( 
                 t h e S i m u l a t i o n E n g i n e P t r - > G e t S i m u l a t i o n E n g i n e I n t e r f a c e ( 
                         * i n i t P a r a m e t e r D a t a b a s e R e a d e r P t r ,   S c e n S i m : : A N Y _ N O D E I D ) ) , 
         t h e A g e n t G i s P t r ( 
                 n e w   M u l t i A g e n t G i s ( 
                         t h i s , 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         i n i t S i m u l a t i o n E n g i n e P t r , 
                         t h e G i s S u b s y s t e m P t r ) ) , 
         i n i t i a l L o c a t i o n F i l e C a c h e P t r ( n e w   I n o r d e r F i l e C a c h e ( ) ) 
 { 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r   =   * i n i t P a r a m e t e r D a t a b a s e R e a d e r P t r ; 
 
         p u b l i c V e h i c l e T a b l e P t r . r e s e t ( 
                 n e w   P u b l i c V e h i c l e T a b l e ( 
                         t h i s , 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                         t h e A g e n t G i s P t r ) ) ; 
 
         t h e R o u t e S e a r c h S u b s y s t e m P t r . r e s e t ( 
                 n e w   A g e n t R o u t e S e a r c h S u b s y s t e m ( 
                         t h e A g e n t G i s P t r , 
                         p u b l i c V e h i c l e T a b l e P t r ) ) ; 
 
         p r o f i l e A n d T a s k T a b l e P t r . r e s e t ( 
                 n e w   A g e n t P r o f i l e A n d T a s k T a b l e ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         p u b l i c V e h i c l e T a b l e P t r , 
                         t h e G i s S u b s y s t e m P t r , 
                         m a s t e r A n y A g e n t P t r ) ) ; 
 
         m a s t e r B u s A g e n t P t r   = 
                 A g e n t : : C r e a t e M a s t e r A g e n t ( 
                         t h i s , 
                         M A S T E R _ B U S _ A G E N T _ I D , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t P r o f i l e ( A G E N T _ T Y P E _ B U S ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t E m p t y T a s k T a b l e ( ) ) ; 
 
         m a s t e r T a x i A g e n t P t r   = 
                 A g e n t : : C r e a t e M a s t e r A g e n t ( 
                         t h i s , 
                         M A S T E R _ T A X I _ A G E N T _ I D , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t P r o f i l e ( A G E N T _ T Y P E _ T A X I ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t E m p t y T a s k T a b l e ( ) ) ; 
 
         p u b l i c V e h i c l e T a b l e P t r - > C o m p l e t e R o u t e A n d V e h i c l e w S c h e d u l e I n i t i a l i z a t i o n ( ) ; 
 
         i f   ( ! t h e P a r a m e t e r D a t a b a s e R e a d e r . R e a d B o o l ( " g i s - r o a d - s e t - i n t e r s e c t i o n - m a r g i n " ) )   { 
                 c e r r   < <   " E r r o r   i n   M u l t i A g e n t   E x t e n s i o n   M o d u l e :   S e t   g i s - r o a d - s e t - i n t e r s e c t i o n - m a r g i n   =   t r u e "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         M a k e S e t O f A l l A g e n t I d s ( * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ,   e n t i r e A g e n t I d s ) ; 
 
         p r o f i l e A n d T a s k T a b l e P t r - > C o m p l e t e I n i t i a l i z e ( 
                 * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                 t h e G i s S u b s y s t e m P t r , 
                 m a s t e r A n y A g e n t P t r , 
                 e n t i r e A g e n t I d s ) ; 
 
         i f   ( t i m e S t e p   <   M U L T I A G E N T _ M I N _ T I M E _ S T E P )   { 
                 c e r r   < <   " E r r o r :     M u l t i - A g e n t   m i n   t i m e   s t e p   i s   1   m s "   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         s e t < A g e n t I d T y p e >   a g e n t I d s ; 
         v e c t o r < s h a r e d _ p t r < B u s T i c k e t >   >   b u s R e s e r v a t i o n P t r s ; 
         v e c t o r < s h a r e d _ p t r < A g e n t >   >   a l l H u m a n A g e n t P t r s ; 
 
         M a k e S e t O f A l l A g e n t I d s ( * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ,   a g e n t I d s ) ; 
 
         t y p e d e f   s e t < N o d e I d > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         m a p < A g e n t I d T y p e ,   V e r t e x >   t a x i A g e n t L o c a t i o n s ; 
 
         f o r ( I t e r T y p e   i t e r   =   a g e n t I d s . b e g i n ( ) ;   i t e r   ! =   a g e n t I d s . e n d ( ) ;   i t e r + + )   { 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d   =   ( * i t e r ) ; 
 
                 s t r i n g   p r o f i l e N a m e   =   M a k e L o w e r C a s e S t r i n g ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d S t r i n g ( 
                                 " m u l t i a g e n t - p r o f i l e - t y p e " ,   a g e n t I d ) ) ; 
 
                 s t r i n g   t a s k N a m e   =   M a k e L o w e r C a s e S t r i n g ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d S t r i n g ( 
                                 " m u l t i a g e n t - b e h a v i o r - t y p e " ,   a g e n t I d ) ) ; 
 
                 i f   ( A S t r i n g S t a r t s W i t h ( p r o f i l e N a m e ,   " t a x i " ) )   { 
 
                         c o n s t   d o u b l e   d i s t a n c e G r a n u l a r i t y M e t e r s   =   0 ; 
                         c o n s t   s t r i n g   p o s i t i o n F i l e N a m e   = 
                                 t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d S t r i n g ( 
                                         " m o b i l i t y - i n i t - p o s i t i o n s - f i l e " , 
                                         a g e n t I d ) ; 
 
                         I n o r d e r F i l e C a c h e   m o b i l i t y F i l e C a c h e F o r T a x i ; 
 
                         T r a c e F i l e M o b i l i t y M o d e l   t r a c e M o b i l i t y F o r T a x i ( 
                                 * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                                 a g e n t I d , 
                                 n u l l I n s t a n c e I d , 
                                 m o b i l i t y F i l e C a c h e F o r T a x i , 
                                 p o s i t i o n F i l e N a m e , 
                                 a g e n t I d , 
                                 d i s t a n c e G r a n u l a r i t y M e t e r s , 
                                 t h e G i s S u b s y s t e m P t r ) ; 
 
                         O b j e c t M o b i l i t y P o s i t i o n   t a x i M o b i l i t y P o s i t i o n ; 
 
                         t r a c e M o b i l i t y F o r T a x i . G e t U n a d j u s t e d P o s i t i o n F o r T i m e ( Z E R O _ T I M E ,   t a x i M o b i l i t y P o s i t i o n ) ; 
 
                         V e r t e x &   t a x i P o s   =   t a x i A g e n t L o c a t i o n s [ a g e n t I d ] ; 
 
                         t a x i P o s . x   =   t a x i M o b i l i t y P o s i t i o n . X _ P o s i t i o n M e t e r s ( ) ; 
                         t a x i P o s . y   =   t a x i M o b i l i t y P o s i t i o n . Y _ P o s i t i o n M e t e r s ( ) ; 
 
                 }   e l s e   i f   ( p r o f i l e N a m e   = =   " t r a i n "   | | 
                                       p r o f i l e N a m e   = =   " b u s "   | | 
                                       p r o f i l e N a m e   = =   " v e h i c l e "   | | 
                                       p r o f i l e N a m e   = =   " p r i v a t e c a r " )   { 
 
                         V e h i c l e T y p e   v e h i c l e T y p e   =   V E H I C L E _ C A R ; 
 
                         i f   ( p r o f i l e N a m e   = =   " t r a i n " )   { 
                                 v e h i c l e T y p e   =   V E H I C L E _ T R A I N ; 
                         }   e l s e   i f   ( p r o f i l e N a m e   = =   " b u s " )   { 
                                 v e h i c l e T y p e   =   V E H I C L E _ B U S ; 
                         }   e l s e   i f   ( p r o f i l e N a m e   = =   " v e h i c l e "   | |   p r o f i l e N a m e   = =   " p r i v a t e c a r " )   { 
                                 v e h i c l e T y p e   =   V E H I C L E _ C A R ; 
                         } 
 
                         ( * t h i s ) . R e s e r v e V e h i c l e N o d e ( a g e n t I d ,   v e h i c l e T y p e ) ; 
 
                 }   e l s e   { 
 
                         s t r i n g   o r i g P r o f i l e N a m e   =   p r o f i l e N a m e ; 
                         s i z e _ t   i d E x c h a n g e P o s   =   p r o f i l e N a m e . f i n d ( " $ n " ) ; 
 
                         i f   ( i d E x c h a n g e P o s   ! =   s t r i n g : : n p o s )   { 
                                 p r o f i l e N a m e   = 
                                         p r o f i l e N a m e . s u b s t r ( 0 ,   i d E x c h a n g e P o s )   + 
                                         C o n v e r t T o S t r i n g ( a g e n t I d )   + 
                                         p r o f i l e N a m e . s u b s t r ( i d E x c h a n g e P o s   +   2 ) ; 
                         } 
                         e l s e   i f   ( p r o f i l e N a m e   = =   " { s i m u l a t i o n _ n o d e _ i d } " )   { 
 
                                 p r o f i l e N a m e   =   C o n v e r t T o S t r i n g ( a g e n t I d ) ; 
                         } / / i f / / 
 
                         c o n s t   s h a r e d _ p t r < A g e n t >   a g e n t P t r ( 
                                 n e w   A g e n t ( 
                                         t h i s , 
                                         t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                                         a g e n t I d , 
                                         ( * t h i s ) . G e t S i m E n g i n e I n t e r f a c e P t r ( a g e n t I d ) , 
                                         p r o f i l e A n d T a s k T a b l e P t r - > G e t P r o f i l e ( p r o f i l e N a m e ) , 
                                         p r o f i l e A n d T a s k T a b l e P t r - > G e t T a s k T a b l e ( t a s k N a m e ,   o r i g P r o f i l e N a m e ) , 
                                         t h e A g e n t G i s P t r , 
                                         p u b l i c V e h i c l e T a b l e P t r , 
                                         t h e R o u t e S e a r c h S u b s y s t e m P t r ) ) ; 
 
                         i f   ( a g e n t P t r - > H a s C a r ( ) )   { 
                                 n e w l y A d d e d V e h i c l e P t r s . p u s h _ b a c k ( a g e n t P t r - > G e t V e h i c l e ( ) ) ; 
                         } 
 
                         c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( a g e n t P t r ) ; 
                         c o n s t   d o u b l e   l a s t D e l a y Q u e r y T r i g g e r   =   r e s o u r c e . L a s t D e l a y Q u e r y T r i g g e r ( ) ; 
                         c o n s t   d o u b l e   n e x t D e l a y Q u e r y T r i g g e r   =   r e s o u r c e . N e x t D e l a y Q u e r y T r i g g e r ( ) ; 
                         c o n s t   d o u b l e   t r i p D e l a y Q u e r y T r i g g e r   =   r e s o u r c e . T r i p D e l a y Q u e r y T r i g g e r ( ) ; 
                         c o n s t   d o u b l e   v e h i c l e D e l a y Q u e r y T r i g g e r   =   r e s o u r c e . V e h i c l e D e l a y Q u e r y T r i g g e r ( ) ; 
                         c o n s t   d o u b l e   c o n g e s t i o n Q u e r y T r i g g e r   =   r e s o u r c e . C o n g e s t i o n Q u e r y T r i g g e r ( ) ; 
                         c o n s t   d o u b l e   u t i l i t y 1 Q u e r y T r i g g e r   =   r e s o u r c e . U t i l i t y 1 Q u e r y T r i g g e r ( ) ; 
                         c o n s t   d o u b l e   u t i l i t y 2 Q u e r y T r i g g e r   =   r e s o u r c e . U t i l i t y 2 Q u e r y T r i g g e r ( ) ; 
 
                         i f   ( l a s t D e l a y Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c I n t e r v a l F o r L a s t V i a P o i n t D e l a y   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         i f   ( n e x t D e l a y Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c I n t e r v a l F o r N e x t V i a P o i n t D e l a y   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         i f   ( t r i p D e l a y Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c I n t e r v a l F o r D e s t i n a t i o n D e l a y   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         i f   ( v e h i c l e D e l a y Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c I n t e r v a l F o r V e h i c l e D e l a y   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         i f   ( c o n g e s t i o n Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c T h r e s h o l d F o r C o n g e s t i o n   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         i f   ( u t i l i t y 1 Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c T h r e s h o l d F o r U t i l i t y 1   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         i f   ( u t i l i t y 2 Q u e r y T r i g g e r   < =   0 )   { 
                                 c e r r   < <   " E r r o r :   S e t   R e c a l c T h r e s h o l d F o r U t i l i t y 2   t o   n o n - z e r o ( >   0 )   v a l u e   i n   A g e n t P r o f i l e "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
 
                         c o n s t   S i m T i m e   w a k e u p T i m e   =   a g e n t P t r - > C a l c u l a t e W a k e u p T i m e ( ) ; 
 
                         a g e n t W a k e u p Q u e u e . p u s h ( A g e n t W a k e u p E n t r y ( w a k e u p T i m e ,   a g e n t P t r ) ) ; 
 
                         w a k e u p T i m e s [ a g e n t I d ]   =   w a k e u p T i m e ; 
 
                         a l l H u m a n A g e n t P t r s . p u s h _ b a c k ( a g e n t P t r ) ; 
                 } 
         } 
 
         / / t h e G i s S u b s y s t e m P t r - > A d d G i s C h a n g e E v e n t H a n d l e r ( 
         / /         m o d e l N a m e , 
         / /         s h a r e d _ p t r < M u l t i A g e n t G i s C h a n g e E v e n t H a n d l e r > (   n e w   M u l t i A g e n t G i s C h a n g e E v e n t H a n d l e r ( t h i s ) ) ) ; 
 
         p u b l i c V e h i c l e T a b l e P t r - > C o m p l e t e A l l P u b l i c V e h i c l e I n i t i a l i z a t i o n ( ) ; 
 
         t h e A g e n t G i s P t r - > C o m p l e t e I n i t i a l i z a t i o n ( 
                 * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                 i n i t S i m u l a t i o n E n g i n e P t r , 
                 * p r o f i l e A n d T a s k T a b l e P t r , 
                 t a x i A g e n t L o c a t i o n s , 
                 p u b l i c V e h i c l e T a b l e P t r ) ; 
 
         / /   s y n c h r o n i z e r   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
         / /   A p p l i c a t i o n   c o n s t r u c t o r   m u s t   n o t   o u t p u t   t r a c e   b e c a u s e   o f   t r a c e   o u t p u t   c o n f l i c t i o n   b e t w e e n   t h r e a d s . 
         / /   I f   a n   a p p l i c a t i o n   o u t p u t   t r a c e   i n   c o n s t r u c t o r ,   c a l l   S y n c A p p l i c a t i o n C r e a t i o n ( )   w i t h o u t   A p p l i c a t i o n C r e a t i o n S y n c h r o n i z e r 
 
         ( * t h i s ) . S e t u p S t a t O u t p u t F i l e ( ) ; 
 
 
         i f   ( i s S c e n a r i o S e t t i n g O u t p u t M o d e )   { 
 
                 ( * t h i s ) . O u t p u t S c e n a r i o S e t t i n g T o C o n f i g ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         a g e n t I d s , 
                         a l l H u m a n A g e n t P t r s , 
                         n e w l y A d d e d V e h i c l e P t r s ) ; 
         } / / i f / / 
 
 } / / M u l t i A g e n t S i m u l a t o r ( ) / / 
 
 # p r a g m a   w a r n i n g ( d e f a u l t : 4 3 5 5 ) 
 
 M u l t i A g e n t S i m u l a t o r : : ~ M u l t i A g e n t S i m u l a t o r ( ) 
 { 
         i s S i m u l a t i o n D o n e   =   t r u e ; 
         t h e A g e n t G i s P t r - > D i s c o n n e c t G i s C o n n e c t i o n ( ) ; 
 
         ( * t h i s ) . D e l e t e A l l N o d e s ( ) ; 
 
         r e s e r v e d V e h i c l e N o d e P t r s . c l e a r ( ) ; 
         t h e A g e n t G i s P t r . r e s e t ( ) ; 
         m a s t e r A n y A g e n t P t r . r e s e t ( ) ; 
         p u b l i c V e h i c l e T a b l e P t r . r e s e t ( ) ; 
 
         m a s t e r B u s A g e n t P t r . r e s e t ( ) ; 
         m a s t e r T a x i A g e n t P t r . r e s e t ( ) ; 
 
         t h e R o u t e S e a r c h S u b s y s t e m P t r . r e s e t ( ) ; 
         t h e S i m u l a t i o n R u n I n t e r f a c e P t r . r e s e t ( ) ; 
 
         e n t i r e A g e n t I d s . c l e a r ( ) ; 
 
         w h i l e ( ! a g e n t W a k e u p Q u e u e . e m p t y ( ) )   { 
                 a g e n t W a k e u p Q u e u e . p o p ( ) ; 
         } 
 
         n e w l y A d d e d A g e n t I d s . c l e a r ( ) ; 
 
         c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n . c l e a r ( ) ; 
         s y n c h r o n i z e d N o d e P t r s . c l e a r ( ) ; 
 
         t i m e I n c r e m e n t T h r e a d P t r . r e s e t ( ) ; 
 
         w h i l e ( ! d e l e t e N o d e I d s . e m p t y ( ) )   { 
                 d e l e t e N o d e I d s . p o p ( ) ; 
         } 
 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r   A g e n t I t e r ; 
 
         f o r ( A g e n t I t e r   i t e r   =   a g e n t P t r s . b e g i n ( ) ; 
                 ( i t e r   ! =   a g e n t P t r s . e n d ( ) ) ;   i t e r + + )   { 
                 ( * i t e r ) - > R e a d y T o D e s t r u c t ( ) ; 
         } / / f o r / / 
         a g e n t P t r s . c l e a r ( ) ; 
 
         w h i l e   ( ! t o o k S y n c h r o n i z e r P t r s . e m p t y ( ) )   { 
                 t o o k S y n c h r o n i z e r P t r s . p o p ( ) ; 
         } 
 
         i t e r T o A g e n t L i s t . c l e a r ( ) ; 
         n e w l y A d d e d V e h i c l e P t r s . c l e a r ( ) ; 
         o w n e r C h a n g e E v e n t s . c l e a r ( ) ; 
 } 
 
 s t r u c t   R e p l a c e L i n e I n f o   { 
         s t r i n g   v a l u e ; 
         s t r i n g   s c o p e S t r i n g ; 
 
         R e p l a c e L i n e I n f o ( )   { } 
 
         e x p l i c i t   R e p l a c e L i n e I n f o ( 
                 c o n s t   s t r i n g &   i n i t V a l u e , 
                 c o n s t   s t r i n g &   i n i t S c o p e S t r i n g   =   s t r i n g ( ) / * = >   g l o b a l * / ) 
                 : 
                 v a l u e ( i n i t V a l u e ) , 
                 s c o p e S t r i n g ( i n i t S c o p e S t r i n g ) 
         { } 
 } ; 
 
 s t a t i c   i n l i n e 
 v o i d   O u t p u t N e w C o n f i g F i l e W i t h R e p l a c e L i n e ( 
         c o n s t   s t r i n g &   i n p u t C o n f i g F i l e N a m e , 
         c o n s t   s t r i n g &   o u t p u t C o n f i g F i l e N a m e , 
         c o n s t   m a p < s t r i n g ,   R e p l a c e L i n e I n f o > &   r e p l a c e L i n e M a p ) 
 { 
         / /   R e m o v e   c o r r e s p o n d i n g   l i n e s   ( s i m p l e   r e p l a c e m e n t ) 
 
         i f s t r e a m   i n S t r e a m ( i n p u t C o n f i g F i l e N a m e . c _ s t r ( ) ) ; 
 
         i f   ( ! i n S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   i n p u t   c o n f i g   f i l e   "   < <   i n p u t C o n f i g F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
         s t r i n g   t m p O u t p u t F i l e N a m e   =   o u t p u t C o n f i g F i l e N a m e   +   " . t m p " ; 
 
         o f s t r e a m   o u t S t r e a m ( t m p O u t p u t F i l e N a m e . c _ s t r ( ) ,   s t d : : i o s : : o u t ) ; 
 
         i f   ( ! o u t S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   o u t p u t   c o n f i g   f i l e   "   < <   t m p O u t p u t F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
         w h i l e ( ! i n S t r e a m . e o f ( ) )   { 
                 s t r i n g   a L i n e ; 
                 g e t l i n e ( i n S t r e a m ,   a L i n e ) ; 
 
                 D e l e t e T r a i l i n g S p a c e s ( a L i n e ) ; 
 
                 i f   ( ! I s A C o n f i g F i l e C o m m e n t L i n e ( a L i n e ) )   { 
                         s i z e _ t   p a r a m e t e r N a m e S t a r t P o s   =   a L i n e . f i n d _ f i r s t _ n o t _ o f ( '   ' ) ; 
 
                         / /   N o   c h e c k i n g   t h e   f i l e   f o r m a t . 
                         / /   ( a l r e a d y   c h e c k e d   b y   " P a r a m e t e r D a t a b a s e R e a d e r " ) 
 
                         i f   ( a L i n e . a t ( p a r a m e t e r N a m e S t a r t P o s )   = =   ' [ ' )   { 
                                 p a r a m e t e r N a m e S t a r t P o s   =   a L i n e . f i n d ( ' ] ' ,   p a r a m e t e r N a m e S t a r t P o s )   +   1 ; 
                                 p a r a m e t e r N a m e S t a r t P o s   =   a L i n e . f i n d _ f i r s t _ n o t _ o f ( '   ' ,   p a r a m e t e r N a m e S t a r t P o s ) ; 
                         } / / i f / / 
 
                         c o n s t   s i z e _ t   p a r a m e t e r N a m e E n d P o s   = 
                                 a L i n e . f i n d _ f i r s t _ o f ( "   " ,   p a r a m e t e r N a m e S t a r t P o s ) ; 
 
                         s t r i n g   p a r a m e t e r N A m e   = 
                                 a L i n e . s u b s t r ( p a r a m e t e r N a m e S t a r t P o s ,   p a r a m e t e r N a m e E n d P o s   -   p a r a m e t e r N a m e S t a r t P o s ) ; 
 
                         C o n v e r t S t r i n g T o L o w e r C a s e ( p a r a m e t e r N A m e ) ; 
 
                         i f   ( r e p l a c e L i n e M a p . f i n d ( p a r a m e t e r N A m e )   ! =   r e p l a c e L i n e M a p . e n d ( ) )   { 
                                 c o n t i n u e ; 
                         } / / i f / / 
                 } / / i f / / 
 
                 o u t S t r e a m   < <   a L i n e   < <   e n d l ; 
         } / / w h i l e / / 
 
         o u t S t r e a m   < <   e n d l ; 
         o u t S t r e a m   < <   " # S i m u l a t e d   S c e n a r i o   S e t t i n g "   < <   e n d l ; 
 
         / /   A d d i t i o n a l   l i n e 
 
         t y p e d e f   m a p < s t r i n g ,   R e p l a c e L i n e I n f o > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   r e p l a c e L i n e M a p . b e g i n ( ) ; 
                 ( i t e r   ! =   r e p l a c e L i n e M a p . e n d ( ) ) ;   i t e r + + )   { 
 
                 c o n s t   R e p l a c e L i n e I n f o &   l i n e I n f o   =   ( * i t e r ) . s e c o n d ; 
 
                 i f   ( ! l i n e I n f o . s c o p e S t r i n g . e m p t y ( ) )   { 
                         o u t S t r e a m   < <   " [ "   < <   l i n e I n f o . s c o p e S t r i n g   < <   " ]   " ; 
                 } / / i f / / 
 
                 o u t S t r e a m   < <   ( * i t e r ) . f i r s t   < <   "   =   "   < <   l i n e I n f o . v a l u e   < <   e n d l ; 
         } / / f o r / / 
 
         i n S t r e a m . c l o s e ( ) ; 
         o u t S t r e a m . c l o s e ( ) ; 
 
         b o o s t : : s y s t e m : : e r r o r _ c o d e   e r r o r C o d e ; 
 
         b o o s t : : f i l e s y s t e m : : r e n a m e ( t m p O u t p u t F i l e N a m e ,   o u t p u t C o n f i g F i l e N a m e ,   e r r o r C o d e ) ; 
 
         i f   ( e r r o r C o d e   ! =   b o o s t : : s y s t e m : : e r r c : : s u c c e s s )   { 
                 c e r r   < <   " E r r o r :   F a i l e d   t o   o u t p u t   "   < <   o u t p u t C o n f i g F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
 } / / O u t p u t N e w C o n f i g F i l e W i t h R e p l a c e L i n e / / 
 
 s t a t i c   i n l i n e 
 s t r i n g   C o n v e r t T o S c o p e S t r i n g ( c o n s t   s e t < A g e n t I d T y p e > &   a g e n t I d s ) 
 { 
         t y p e d e f   s e t < A g e n t I d T y p e > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         c o n s t   A g e n t I d T y p e   i n v a l i d A g e n t I d   =   s t a t i c _ c a s t < A g e n t I d T y p e > ( - 1 ) ; 
 
         A g e n t I d T y p e   s c o p e S t a r t A g e n t I d   =   i n v a l i d A g e n t I d ; 
         A g e n t I d T y p e   s c o p e E n d A g e n t I d   =   i n v a l i d A g e n t I d ; 
 
         v e c t o r < p a i r < A g e n t I d T y p e ,   A g e n t I d T y p e >   >   a g e n t I d P a i r s ; 
 
         f o r ( I t e r T y p e   i t e r   =   a g e n t I d s . b e g i n ( ) ; 
                 ( i t e r   ! =   a g e n t I d s . e n d ( ) ) ;   i t e r + + )   { 
 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d   =   ( * i t e r ) ; 
 
                 i f   ( a g e n t I d   = =   ( s c o p e E n d A g e n t I d   +   1 ) )   { 
 
                         s c o p e E n d A g e n t I d   =   a g e n t I d ; 
                 } 
                 e l s e   { 
 
                         i f   ( s c o p e S t a r t A g e n t I d   ! =   i n v a l i d A g e n t I d )   { 
                                 a g e n t I d P a i r s . p u s h _ b a c k ( m a k e _ p a i r ( s c o p e S t a r t A g e n t I d ,   s c o p e E n d A g e n t I d ) ) ; 
                         } / / i f / / 
 
                         s c o p e S t a r t A g e n t I d   =   a g e n t I d ; 
                         s c o p e E n d A g e n t I d   =   a g e n t I d ; 
 
                 } / / i f / / 
         } / / f o r / / 
 
         i f   ( s c o p e S t a r t A g e n t I d   ! =   i n v a l i d A g e n t I d )   { 
                 a g e n t I d P a i r s . p u s h _ b a c k ( m a k e _ p a i r ( s c o p e S t a r t A g e n t I d ,   s c o p e E n d A g e n t I d ) ) ; 
         } / / i f / / 
 
         o s t r i n g s t r e a m   o u t S t r e a m ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a g e n t I d P a i r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   p a i r < A g e n t I d T y p e ,   A g e n t I d T y p e > &   a g e n t I d P a i r   =   a g e n t I d P a i r s [ i ] ; 
 
                 i f   ( i   >   0 )   { 
                         o u t S t r e a m   < <   " ,   " ; 
                 } / / i f / / 
 
                 i f   ( a g e n t I d P a i r . f i r s t   = =   a g e n t I d P a i r . s e c o n d )   { 
                         o u t S t r e a m   < <   a g e n t I d P a i r . f i r s t ; 
                 } 
                 e l s e   { 
                         o u t S t r e a m   < <   a g e n t I d P a i r . f i r s t   < <   " - "   < <   a g e n t I d P a i r . s e c o n d ; 
                 } / / i f / / 
         } / / f o r / / 
 
         r e t u r n   o u t S t r e a m . s t r ( ) ; 
 
 } / / C o n v e r t T o S c o p e S t r i n g / / 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O u t p u t S c e n a r i o S e t t i n g T o C o n f i g ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s e t < A g e n t I d T y p e > &   a g e n t I d s , 
         c o n s t   v e c t o r < s h a r e d _ p t r < A g e n t >   > &   a l l H u m a n A g e n t P t r s , 
         c o n s t   l i s t < s h a r e d _ p t r < V e h i c l e >   > &   a l l P r i v a t e C a r P t r s ) 
 { 
         / /   O u t p u t   c u r r e n t   s c e n a r i o   s e t t i n g s 
 
         c o n s t   s t r i n g   s c e n a r i o N a m e   =   b o o s t : : f i l e s y s t e m : : b a s e n a m e ( o u t p u t C o n f i g F i l e N a m e ) ; 
 
         c o n s t   s t r i n g   i n i t P o s F i l e N a m e   =   s c e n a r i o N a m e   +   " . p o s " ; 
 
         ( * t h i s ) . O u t p u t A l l H u m a n A g e n t I n i t i a l L o c a t i o n T o P o s F i l e ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 a g e n t I d s , 
                 a l l H u m a n A g e n t P t r s , 
                 a l l P r i v a t e C a r P t r s , 
                 i n i t P o s F i l e N a m e ) ; 
 
         c o n s t   s t r i n g   s c e n a r i o P r e f i x   =   s c e n a r i o N a m e   +   " _ " ; 
         c o n s t   s t r i n g   b e h a v i o r F i l e N a m e   =   t h e P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( " m u l t i a g e n t - b e h a v i o r - f i l e " ) ; 
 
         c o n s t   b o o s t : : f i l e s y s t e m : : p a t h   o r i g C o n f i g P a t h ( i n p u t C o n f i g F i l e N a m e ) ; 
         c o n s t   b o o s t : : f i l e s y s t e m : : p a t h   d e s t C o n f i g P a t h ( o u t p u t C o n f i g F i l e N a m e ) ; 
 
         s t r i n g   d e s t S h a p e D i r N a m e ; 
         s t r i n g   d e s t B e h a v i o r F i l e N a m e ; 
 
         i f   ( o r i g C o n f i g P a t h   = =   d e s t C o n f i g P a t h )   { 
                 d e s t S h a p e D i r N a m e   =   t h e P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( " g i s - o b j e c t - f i l e - p a t h " ) ; 
                 d e s t B e h a v i o r F i l e N a m e   =   b e h a v i o r F i l e N a m e ; 
         } 
         e l s e   { 
                 d e s t S h a p e D i r N a m e   =   s c e n a r i o P r e f i x   +   " s h a p e s / " ; 
                 d e s t B e h a v i o r F i l e N a m e   =   s c e n a r i o P r e f i x   +   " A g e n t B e h a v i o r s . t x t " ; 
         } / / i f / / 
 
         v e c t o r < s t r i n g >   o u t p u t S h a p e F i l e N a m e s ; 
 
         ( * t h i s ) . O v e r w r i t e G i s S h a p e F i l e ( 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 d e s t S h a p e D i r N a m e , 
                 o u t p u t S h a p e F i l e N a m e s ) ; 
 
         ( * t h i s ) . O v e r w r i t e B e h a v i o r F i l e W i t h P r e s e n t I n i t i a l L o c a t i o n ( 
                 b e h a v i o r F i l e N a m e , 
                 d e s t B e h a v i o r F i l e N a m e ) ; 
 
         / /   O u t p u t   c o n f i g 
 
         m a p < s t r i n g ,   R e p l a c e L i n e I n f o >   r e p l a c e L i n e M a p ; 
 
         c o n s t   s t r i n g   s c o p e S t r i n g   =   C o n v e r t T o S c o p e S t r i n g ( a g e n t I d s ) ; 
 
         r e p l a c e L i n e M a p [ " m o b i l i t y - i n i t - p o s i t i o n s - f i l e " ]   =   R e p l a c e L i n e I n f o ( i n i t P o s F i l e N a m e ,   s c o p e S t r i n g ) ; 
         r e p l a c e L i n e M a p [ " g i s - o b j e c t - f i l e - p a t h " ]   =   R e p l a c e L i n e I n f o ( d e s t S h a p e D i r N a m e ) ; 
         r e p l a c e L i n e M a p [ " m u l t i a g e n t - b e h a v i o r - f i l e " ]   =   R e p l a c e L i n e I n f o ( d e s t B e h a v i o r F i l e N a m e ) ; 
 
         o s t r i n g s t r e a m   s h a p e L i n e S t r e a m ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   o u t p u t S h a p e F i l e N a m e s . s i z e ( ) ;   i + + )   { 
                 s h a p e L i n e S t r e a m   < <   "   "   < <   o u t p u t S h a p e F i l e N a m e s [ i ] ; 
         } / / f o r / / 
 
         r e p l a c e L i n e M a p [ " g i s - o b j e c t - f i l e s " ]   =   R e p l a c e L i n e I n f o ( s h a p e L i n e S t r e a m . s t r ( ) ) ; 
 
         O u t p u t N e w C o n f i g F i l e W i t h R e p l a c e L i n e ( 
                 i n p u t C o n f i g F i l e N a m e , 
                 o u t p u t C o n f i g F i l e N a m e , 
                 r e p l a c e L i n e M a p ) ; 
 
 } / / O u t p u t S c e n a r i o S e t t i n g T o C o n f i g / / 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O u t p u t A l l H u m a n A g e n t I n i t i a l L o c a t i o n T o P o s F i l e ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s e t < A g e n t I d T y p e > &   a g e n t I d s , 
         c o n s t   v e c t o r < s h a r e d _ p t r < A g e n t >   > &   a l l H u m a n A g e n t P t r s , 
         c o n s t   l i s t < s h a r e d _ p t r < V e h i c l e >   > &   a l l P r i v a t e C a r P t r s , 
         c o n s t   s t r i n g &   o u t p u t F i l e N a m e ) 
 { 
         t y p e d e f   s e t < A g e n t I d T y p e > : : c o n s t _ i t e r a t o r   A g e n t I d I t e r ; 
 
         m a p < A g e n t I d T y p e ,   O b j e c t M o b i l i t y P o s i t i o n >   m o b i l i t y P o s i t i o n s ; 
 
         I n o r d e r F i l e C a c h e   m o b i l i t y F i l e C a c h e F o r T a x i ; 
 
         f o r ( A g e n t I d I t e r   i t e r   =   a g e n t I d s . b e g i n ( ) ;   i t e r   ! =   a g e n t I d s . e n d ( ) ;   i t e r + + )   { 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d   =   ( * i t e r ) ; 
 
                 c o n s t   s t r i n g   p o s i t i o n F i l e N a m e   = 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d S t r i n g ( 
                                 " m o b i l i t y - i n i t - p o s i t i o n s - f i l e " ,   a g e n t I d ) ; 
 
                 T r a c e F i l e M o b i l i t y M o d e l   t r a c e M o b i l i t y F o r T a x i ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         a g e n t I d , 
                         n u l l I n s t a n c e I d , 
                         m o b i l i t y F i l e C a c h e F o r T a x i , 
                         p o s i t i o n F i l e N a m e , 
                         a g e n t I d , 
                         0 / * d i s t a n c e G r a n u l a r i t y M e t e r s * / , 
                         t h e G i s S u b s y s t e m P t r ) ; 
 
                 O b j e c t M o b i l i t y P o s i t i o n   m o b i l i t y P o s i t i o n ; 
 
                 t r a c e M o b i l i t y F o r T a x i . G e t U n a d j u s t e d P o s i t i o n F o r T i m e ( Z E R O _ T I M E ,   m o b i l i t y P o s i t i o n ) ; 
 
                 m o b i l i t y P o s i t i o n s [ a g e n t I d ]   =   m o b i l i t y P o s i t i o n ; 
         } / / f o r / / 
 
         / /   O v e r w r i t e   i n i t i a l   p o s i t i o n   f o r   h u m a n   a g e n t 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a l l H u m a n A g e n t P t r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   s h a r e d _ p t r < A g e n t > &   h u m a n A g e n t P t r   =   a l l H u m a n A g e n t P t r s [ i ] ; 
                 c o n s t   A g e n t R e s o u r c e   r e s o u r c e ( h u m a n A g e n t P t r ) ; 
 
                 m o b i l i t y P o s i t i o n s [ h u m a n A g e n t P t r - > G e t A g e n t I d ( ) ]   = 
                         r e s o u r c e . M o b i l i t y P o s i t i o n ( ) ; 
         } / / f o r / / 
 
         / /   A s s i g n   v e h i c l e ( p r i v a t e   c a r )   w i t h   t h e   s a m e   a l g o r i t h m   a s   t h e   s i m u l a t i o n 
 
         q u e u e < s h a r e d _ p t r < V e h i c l e N o d e >   >   v e h i c l e N o d e P t r s   = 
                 r e s e r v e d V e h i c l e N o d e P t r s . a t ( V E H I C L E _ C A R ) ;   / / d e e p   c o p y 
 
         t y p e d e f   l i s t < s h a r e d _ p t r < V e h i c l e >   > : : c o n s t _ i t e r a t o r   V e h i c l e I t e r ; 
 
         f o r ( V e h i c l e I t e r   i t e r   =   a l l P r i v a t e C a r P t r s . b e g i n ( ) ;   i t e r   ! =   a l l P r i v a t e C a r P t r s . e n d ( ) ;   i t e r + + )   { 
                 c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r   =   ( * i t e r ) ; 
 
                 i f   ( v e h i c l e N o d e P t r s . e m p t y ( ) )   { 
                         c e r r   < <   " E r r o r :   n o t   e n o u g h   v e h i c l e   n o d e "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } / / i f / / 
 
                 s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r   =   v e h i c l e N o d e P t r s . f r o n t ( ) ; 
 
                 v e h i c l e N o d e P t r - > S e t V e h i c l e ( 
                         t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                         t h e A g e n t G i s P t r , 
                         ( * t h i s ) . C u r r e n t T i m e ( ) , 
                         v e h i c l e P t r ) ; 
 
                 m o b i l i t y P o s i t i o n s [ v e h i c l e N o d e P t r - > G e t A g e n t I d ( ) ]   = 
                         v e h i c l e N o d e P t r - > G e t C u r r e n t L o c a t i o n ( ) ; 
 
                 v e h i c l e N o d e P t r s . p o p ( ) ; 
         } / / f o r / / 
 
 
         o f s t r e a m   o u t S t r e a m ( o u t p u t F i l e N a m e . c _ s t r ( ) ,   s t d : : i o s : : o u t ) ; 
 
         i f   ( ! o u t S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   p o s i t i o n   f i l e   "   < <   o u t p u t F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
         t y p e d e f   m a p < A g e n t I d T y p e ,   O b j e c t M o b i l i t y P o s i t i o n > : : c o n s t _ i t e r a t o r   P o s i t i o n I t e r ; 
 
         o u t S t r e a m . p r e c i s i o n ( 3 0 ) ; 
 
         f o r ( P o s i t i o n I t e r   i t e r   =   m o b i l i t y P o s i t i o n s . b e g i n ( ) ; 
                 ( i t e r   ! =   m o b i l i t y P o s i t i o n s . e n d ( ) ) ;   i t e r + + )   { 
 
                 u s i n g   s t d : : s e t w ; 
 
                 c o n s t   A g e n t I d T y p e   a g e n t I d   =   ( * i t e r ) . f i r s t ; 
                 c o n s t   O b j e c t M o b i l i t y P o s i t i o n &   m o b i l i t y P o s i t i o n   =   ( * i t e r ) . s e c o n d ; 
 
                 o u t S t r e a m 
                         < <   a g e n t I d   < <   '   ' 
                         < <   " 0   " 
                         < <   s e t w ( 1 1 )   < <   m o b i l i t y P o s i t i o n . X _ P o s i t i o n M e t e r s ( )   < <   '   ' 
                         < <   s e t w ( 1 1 )   < <   m o b i l i t y P o s i t i o n . Y _ P o s i t i o n M e t e r s ( )   < <   '   ' 
                         < <   m o b i l i t y P o s i t i o n . H e i g h t F r o m G r o u n d M e t e r s ( )   < <   '   ' 
                         < <   m o b i l i t y P o s i t i o n . A t t i t u d e A z i m u t h F r o m N o r t h C l o c k w i s e D e g r e e s ( )   < <   '   ' 
                         < <   m o b i l i t y P o s i t i o n . A t t i t u d e E l e v a t i o n F r o m H o r i z o n D e g r e e s ( )   < <   e n d l ; 
 
         } / / f o r / / 
 
 } / / O u t p u t A l l H u m a n A g e n t I n i t i a l L o c a t i o n T o P o s F i l e / / 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O v e r w r i t e G i s S h a p e F i l e ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s t r i n g &   d e s t S h a p e D i r N a m e , 
         v e c t o r < s t r i n g > &   o u t p u t S h a p e F i l e N a m e s ) 
 { 
         c o n s t   s t r i n g   o r i g S h a p e D i r N a m e   = 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( " g i s - o b j e c t - f i l e - p a t h " ) ; 
 
         c o n s t   b o o s t : : f i l e s y s t e m : : p a t h   o r i g S h a p e D i r P a t h ( o r i g S h a p e D i r N a m e ) ; 
         c o n s t   b o o s t : : f i l e s y s t e m : : p a t h   d e s t S h a p e D i r P a t h ( d e s t S h a p e D i r N a m e ) ; 
 
         i f   ( o r i g S h a p e D i r P a t h   = =   d e s t S h a p e D i r P a t h )   { 
 
                 / / o v e r w r i t e   o r i g i n a l   s h a p e 
         } 
         e l s e   { 
                 u s i n g   b o o s t : : f i l e s y s t e m : : d i r e c t o r y _ i t e r a t o r ; 
 
                 b o o s t : : s y s t e m : : e r r o r _ c o d e   e r r o r C o d e ; 
 
                 b o o s t : : f i l e s y s t e m : : c r e a t e _ d i r e c t o r i e s ( d e s t S h a p e D i r P a t h ,   e r r o r C o d e ) ; 
 
                 i f   ( e r r o r C o d e   ! =   b o o s t : : s y s t e m : : e r r c : : s u c c e s s )   { 
                         c e r r   < <   " E r r o r :   F a i l e d   t o   c r e a t e   d i r e c t o r y   "   < <   d e s t S h a p e D i r N a m e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } / / i f / / 
 
                 d i r e c t o r y _ i t e r a t o r   e n d I t e r ; 
 
                 f o r ( d i r e c t o r y _ i t e r a t o r   d i r I t e r ( o r i g S h a p e D i r N a m e ) ; 
                         ( d i r I t e r   ! =   e n d I t e r ) ;   d i r I t e r + + )   { 
 
                         c o n s t   b o o s t : : f i l e s y s t e m : : p a t h &   f i l e P a t h   =   * d i r I t e r ; 
 
                         i f   ( ! b o o s t : : f i l e s y s t e m : : i s _ d i r e c t o r y ( f i l e P a t h ) )   { 
                                 b o o s t : : f i l e s y s t e m : : c o p y _ f i l e ( f i l e P a t h ,   d e s t S h a p e D i r P a t h   /   f i l e P a t h . f i l e n a m e ( ) ,   e r r o r C o d e ) ; 
 
                                 i f   ( e r r o r C o d e   ! =   b o o s t : : s y s t e m : : e r r c : : s u c c e s s )   { 
                                         c e r r   < <   " E r r o r :   F a i l e d   c o p i n g   "   < <   f i l e P a t h   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } / / i f / / 
                         } / / i f / / 
                 } / / f o r / / 
         } / / i f / / 
 
         c o n s t   s t r i n g   o r i g S h a p e F i l e N a m e s   = 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( " g i s - o b j e c t - f i l e s " ) ; 
 
         b o o l   s u c c e s s ; 
         v e c t o r < s t r i n g >   a V e c t o r ; 
 
         C o n v e r t A S t r i n g I n t o A V e c t o r O f S t r i n g s ( o r i g S h a p e F i l e N a m e s ,   s u c c e s s ,   a V e c t o r ) ; 
 
         i f   ( ! s u c c e s s )   { 
                 c e r r   < <   " E r r o r :   F a i l e d   t o   c o n v e r t   t o   s t r i n g   v e c t o r   "   < <   o r i g S h a p e F i l e N a m e s   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
         s e t < s t r i n g >   s h a p e F i l e N a m e S e t ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a V e c t o r . s i z e ( ) ;   i + + )   { 
                 s h a p e F i l e N a m e S e t . i n s e r t ( a V e c t o r [ i ] ) ; 
         } / / f o r / / 
 
         / /   O v e r w r i t e   e n t r a n c e   a n d   r o a d   s h a p e   f i l e . 
 
         s h a p e F i l e N a m e S e t . i n s e r t ( " e n t r a n c e . s h p " ) ; 
         t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . O v t p u t C u r r e n t E n t r a n c e S h a p e F i l e ( d e s t S h a p e D i r N a m e ) ; 
 
         / / R o a d   i m p o r t / e x p o r t   f e a t u r e 
         / / f u t u r e / /   s h a p e F i l e N a m e S e t . i n s e r t ( " r o a d . s h p " ) ; 
         / / f u t u r e / /   s h a p e F i l e N a m e S e t . i n s e r t ( " i n t e r s e c t i o n . s h p " ) ; 
         / / f u t u r e / /   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . O v t p u t C u r r e n t R o a d S h a p e F i l e ( d e s t S h a p e D i r N a m e ) ; 
         / / f u t u r e / /   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) . O v t p u t C u r r e n t I n t e r s e c t i o n S h a p e F i l e ( d e s t S h a p e D i r N a m e ) ; 
 
         o u t p u t S h a p e F i l e N a m e s . c l e a r ( ) ; 
 
         t y p e d e f   s e t < s t r i n g > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   s h a p e F i l e N a m e S e t . b e g i n ( ) ; 
                 ( i t e r   ! =   s h a p e F i l e N a m e S e t . e n d ( ) ) ;   i t e r + + )   { 
                 o u t p u t S h a p e F i l e N a m e s . p u s h _ b a c k ( * i t e r ) ; 
         } / / f o r / / 
 
 } / / O v e r w r i t e G i s S h a p e F i l e / / 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O v e r w r i t e B e h a v i o r F i l e W i t h P r e s e n t I n i t i a l L o c a t i o n ( 
         c o n s t   s t r i n g &   o r i g B e h a v i o r F i l e N a m e , 
         c o n s t   s t r i n g &   d e s t B e h a v i o r F i l e N a m e ) 
 { 
         / /   R e m o v e   c o r r e s p o n d i n g   l i n e s   ( s i m p l e   r e p l a c e m e n t ) 
 
         i f s t r e a m   i n S t r e a m ( o r i g B e h a v i o r F i l e N a m e . c _ s t r ( ) ) ; 
 
         i f   ( ! i n S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   i n p u t   c o n f i g   f i l e   "   < <   o r i g B e h a v i o r F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
         s t r i n g   t m p O u t p u t F i l e N a m e   =   d e s t B e h a v i o r F i l e N a m e   +   " . t m p " ; 
 
         o f s t r e a m   o u t S t r e a m ( t m p O u t p u t F i l e N a m e . c _ s t r ( ) ,   s t d : : i o s : : o u t ) ; 
 
         i f   ( ! o u t S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   o u t p u t   c o n f i g   f i l e   "   < <   t m p O u t p u t F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
         c o n s t   s t r i n g   i n i t i a l L o c a t i o n S t r i n g   =   " I n i t i a l L o c a t i o n " ; 
 
         w h i l e ( ! i n S t r e a m . e o f ( ) )   { 
                 s t r i n g   a L i n e ; 
                 g e t l i n e ( i n S t r e a m ,   a L i n e ) ; 
 
                 D e l e t e T r a i l i n g S p a c e s ( a L i n e ) ; 
 
                 i f   ( ! I s A C o n f i g F i l e C o m m e n t L i n e ( a L i n e ) )   { 
 
                         c o n s t   s i z e _ t   i n i t i a l L o c a t i o n P o s   =   a L i n e . f i n d ( i n i t i a l L o c a t i o n S t r i n g ) ; 
 
                         i f   ( i n i t i a l L o c a t i o n P o s   ! =   s t r i n g : : n p o s )   { 
                                 c o n s t   s i z e _ t   e q u a l P o s   =   a L i n e . f i n d _ f i r s t _ n o t _ o f ( "   " ,   i n i t i a l L o c a t i o n P o s   +   i n i t i a l L o c a t i o n S t r i n g . l e n g t h ( ) ) ; 
 
                                 i f   ( ( e q u a l P o s   ! =   s t r i n g : : n p o s )   & & 
                                         ( a L i n e [ e q u a l P o s ]   = =   ' = ' ) )   { 
 
                                         c o n s t   s i z e _ t   l o c a t i o n S t a r t P o s   =   a L i n e . f i n d _ f i r s t _ n o t _ o f ( " =   " ,   e q u a l P o s ) ; 
 
                                         i f   ( l o c a t i o n S t a r t P o s   ! =   s t r i n g : : n p o s )   { 
                                                 c o n s t   s i z e _ t   l o c a t i o n E n d P o s   =   a L i n e . f i n d _ f i r s t _ o f ( " ,   " ,   l o c a t i o n S t a r t P o s ) ; 
 
                                                 o u t S t r e a m 
                                                         < <   a L i n e . s u b s t r ( 0 ,   e q u a l P o s ) 
                                                         < <   " =   P r e s e n t L o c a t i o n " ; 
 
                                                 i f   ( l o c a t i o n E n d P o s   ! =   s t r i n g : : n p o s )   { 
                                                         o u t S t r e a m   < <   a L i n e . s u b s t r ( l o c a t i o n E n d P o s ) ; 
                                                 } / / i f / / 
 
                                                 o u t S t r e a m   < <   e n d l ; 
                                                 c o n t i n u e ; 
 
                                         } / / i f / / 
 
                                 } / / i f / / 
 
                         } / / i f / / 
 
                 } / / i f / / 
 
                 o u t S t r e a m   < <   a L i n e   < <   e n d l ; 
         } / / w h i l e / / 
 
         i n S t r e a m . c l o s e ( ) ; 
         o u t S t r e a m . c l o s e ( ) ; 
 
         b o o s t : : s y s t e m : : e r r o r _ c o d e   e r r o r C o d e ; 
 
         b o o s t : : f i l e s y s t e m : : r e n a m e ( t m p O u t p u t F i l e N a m e ,   d e s t B e h a v i o r F i l e N a m e ,   e r r o r C o d e ) ; 
 
         i f   ( e r r o r C o d e   ! =   b o o s t : : s y s t e m : : e r r c : : s u c c e s s )   { 
                 c e r r   < <   " E r r o r :   F a i l e d   t o   o u t p u t   "   < <   d e s t B e h a v i o r F i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } / / i f / / 
 
 } / / O v e r w r i t e B e h a v i o r F i l e W i t h P r e s e n t I n i t i a l L o c a t i o n / / 
 
 M u l t i A g e n t S i m u l a t o r : : P r o f i l e V a l u e O u t p u t S u b s y s t e m : : P r o f i l e V a l u e O u t p u t S u b s y s t e m ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   i n i t P a r a m e t e r D a t a b a s e R e a d e r ) 
 { 
         i f   ( i n i t P a r a m e t e r D a t a b a s e R e a d e r . P a r a m e t e r E x i s t s ( " m u l t i a g e n t - p r o f i l e - v a l u e - o u t p u t - f i l e " ) )   { 
                 c o n s t   s t r i n g   p r o f i l e V a l u e O u t p u t F i l e N a m e   = 
                         i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( " m u l t i a g e n t - p r o f i l e - v a l u e - o u t p u t - f i l e " ) ; 
 
                 c o n s t   s t r i n g   a g e n t P r o f i l e F i l e P a t h   = 
                         i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( " m u l t i a g e n t - p r o f i l e - f i l e " ) ; 
 
                 i f   ( a g e n t P r o f i l e F i l e P a t h   = =   p r o f i l e V a l u e O u t p u t F i l e N a m e )   { 
                         c e r r   < <   " E r r o r :   S e t   \ " m u l t i a g e n t - p r o f i l e - v a l u e - o u t p u t - f i l e \ "   v a l u e   o t h e r   t h a n   \ " m u l t i a g e n t - p r o f i l e - f i l e \ "   v a l u e . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 p r o f i l e V a l u e O u t p u t F i l e . o p e n ( p r o f i l e V a l u e O u t p u t F i l e N a m e . c _ s t r ( ) ) ; 
                 p r o f i l e V a l u e O u t p u t F i l e . p r e c i s i o n ( 3 0 ) ; 
 
                 i f   ( ! p r o f i l e V a l u e O u t p u t F i l e . i s _ o p e n ( ) )   { 
                         c e r r   < <   " E r r o r :   C o u l d   n o t   o p e n   p r o f i l e   v a l u e   o u t p u t   f i l e   "   < <   p r o f i l e V a l u e O u t p u t F i l e N a m e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
         } 
 } 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : R u n S i m u l a t i o n U n t i l ( c o n s t   S i m T i m e &   s n a p s h o t T i m e ) 
 { 
         w h i l e   ( c u r r e n t T i m e   < =   s n a p s h o t T i m e )   { 
                 t h e S i m u l a t i o n R u n I n t e r f a c e P t r - > S c h e d u l e E v e n t ( 
                         u n i q u e _ p t r < S i m u l a t i o n E v e n t > ( n e w   A d v a n c e T i m e S t e p E v e n t ( t h i s ) ) ,   c u r r e n t T i m e ) ; 
 
                 t h e S i m u l a t i o n E n g i n e P t r - > R u n S i m u l a t i o n S e q u e n t i a l l y ( c u r r e n t T i m e ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d v a n c e T i m e S t e p ( ) 
 { 
         i f   ( i s D e b u g M o d e )   { 
                 c o u t   < <   " S i m T i m e   =   "   < <   C o n v e r t T i m e T o D o u b l e S e c s ( c u r r e n t T i m e )   < <   " [ s ] "   < <   e n d l ; 
         } 
 
         n e w l y A d d e d A g e n t I d s . c l e a r ( ) ; 
 
         ( * t h i s ) . A d d V e h i c l e ( ) ; 
 
         w h i l e   ( ! a g e n t W a k e u p Q u e u e . e m p t y ( )   & & 
                       a g e n t W a k e u p Q u e u e . t o p ( ) . t i m e   < =   c u r r e n t T i m e )   { 
 
                 ( * t h i s ) . A d d A g e n t ( a g e n t W a k e u p Q u e u e . t o p ( ) . a g e n t P t r ) ; 
 
                 a g e n t W a k e u p Q u e u e . p o p ( ) ; 
         } 
 
         ( * t h i s ) . C h a n g e A g e n t O w n e r I f N e c e s s a r y ( ) ; 
 
         ( * t h i s ) . I n c r e m e n t T i m e S t e p ( ) ; 
 
         c u r r e n t T i m e   + =   t i m e S t e p ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d V e h i c l e ( ) 
 { 
         v e c t o r < s h a r e d _ p t r < T r a i n >   >   t r a i n P t r s ; 
         v e c t o r < s h a r e d _ p t r < B u s >   >   b u s P t r s ; 
 
         p u b l i c V e h i c l e T a b l e P t r - > C r e a t e P u b l i c V e h i c l e s ( c u r r e n t T i m e ,   t r a i n P t r s ,   b u s P t r s ) ; 
 
         ( * t h i s ) . A d d T r a i n ( t r a i n P t r s ) ; 
 
         ( * t h i s ) . A d d B u s ( b u s P t r s ) ; 
 
         ( * t h i s ) . A d d C a r ( ) ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d T r a i n ( c o n s t   v e c t o r < s h a r e d _ p t r < T r a i n >   > &   t r a i n P t r s ) 
 { 
         i f   ( t r a i n P t r s . e m p t y ( ) )   { 
                 r e t u r n ; 
         } 
 
         q u e u e < s h a r e d _ p t r < V e h i c l e N o d e >   > &   t r a i n N o d e P t r s   =   r e s e r v e d V e h i c l e N o d e P t r s . a t ( V E H I C L E _ T R A I N ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   t r a i n P t r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   s h a r e d _ p t r < T r a i n > &   t r a i n P t r   =   t r a i n P t r s [ i ] ; 
 
                 i f   ( t r a i n N o d e P t r s . s i z e ( )   <   t r a i n P t r s . s i z e ( ) )   { 
                         c e r r   < <   " E r r o r :   n o t   e n o u g h   t r a i n   n o d e "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 a s s e r t ( ! t r a i n N o d e P t r s . e m p t y ( ) ) ; 
                 c o n s t   s h a r e d _ p t r < V e h i c l e N o d e >   t r a i n N o d e P t r   =   t r a i n N o d e P t r s . f r o n t ( ) ; 
                 c o n s t   A g e n t I d T y p e   a g e n t I d   =   t r a i n N o d e P t r - > G e t A g e n t I d ( ) ; 
 
                 s h a r e d _ p t r < A g e n t >   t r a i n D r i v e r P t r   =   A g e n t : : C r e a t e T r a i n D r i v e r A g e n t ( 
                         t h i s , 
                         a g e n t I d , 
                         ( * t h i s ) . G e t S i m E n g i n e I n t e r f a c e P t r ( a g e n t I d ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t P r o f i l e ( A G E N T _ T Y P E _ B U S ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t E m p t y T a s k T a b l e ( ) , 
                         t h e A g e n t G i s P t r , 
                         p u b l i c V e h i c l e T a b l e P t r , 
                         t h e R o u t e S e a r c h S u b s y s t e m P t r , 
                         t r a i n N o d e P t r , 
                         t r a i n P t r ) ; 
 
                 t r a i n P t r - > S e t D r i v e r A g e n t I d ( a g e n t I d ) ; 
 
                 ( * t h i s ) . A d d N o d e ( t r a i n N o d e P t r ) ; 
                 ( * t h i s ) . A d d A g e n t W i t h o u t N o d e G e n e r a t i o n ( t r a i n D r i v e r P t r ) ; 
 
                 t r a i n N o d e P t r - > S e t P u b l i c V e h i c l e ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         t h e A g e n t G i s P t r , 
                         ( * t h i s ) . C u r r e n t T i m e ( ) , 
                         t r a i n P t r ) ; 
 
                 t h e A g e n t G i s P t r - > A d d T r a i n ( t r a i n P t r ) ; 
 
                 t r a i n N o d e P t r s . p o p ( ) ; 
 
                 ( * t h i s ) . O u t p u t T r a c e ( " C r e a t e   T r a i n   "   +   C o n v e r t T o S t r i n g ( t r a i n N o d e P t r - > G e t A g e n t I d ( ) ) ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d B u s ( c o n s t   v e c t o r < s h a r e d _ p t r < B u s >   > &   b u s P t r s ) 
 { 
         i f   ( b u s P t r s . e m p t y ( ) )   { 
                 r e t u r n ; 
         } 
 
 
         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   b u s P t r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   s h a r e d _ p t r < B u s > &   b u s P t r   =   b u s P t r s [ i ] ; 
 
                 q u e u e < s h a r e d _ p t r < V e h i c l e N o d e >   > &   b u s N o d e P t r s   = 
                         r e s e r v e d V e h i c l e N o d e P t r s . a t ( b u s P t r - > G e t V e h i c l e T y p e ( ) ) ; 
 
                 i f   ( b u s N o d e P t r s . e m p t y ( ) )   { 
                         c e r r   < <   " E r r o r :   n o t   e n o u g h   b u s   n o d e "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 c o n s t   s h a r e d _ p t r < V e h i c l e N o d e >   b u s N o d e P t r   =   b u s N o d e P t r s . f r o n t ( ) ; 
                 c o n s t   A g e n t I d T y p e   a g e n t I d   =   b u s N o d e P t r - > G e t A g e n t I d ( ) ; 
                 c o n s t   R o a d I d T y p e   r o a d I d   =   b u s P t r - > G e t S t a r t R o a d I d ( ) ; 
                 c o n s t   B u s S t o p I d T y p e   s t a r t B u s S t o p I d   =   b u s P t r - > G e t S t a r t B u s S t o p I d ( ) ; 
                 c o n s t   V e r t e x I d T y p e   v e r t e x I d   =   s u b s y s t e m . G e t B u s S t o p ( s t a r t B u s S t o p I d ) . G e t V e r t e x I d ( ) ; 
                 c o n s t   s i z e _ t   l a n e N u m b e r   =   s u b s y s t e m . G e t R o a d ( r o a d I d ) . G e t O u t s i d e O u t g o i n g L a n e N u m b e r ( v e r t e x I d ) ; 
 
                 s h a r e d _ p t r < V e h i c l e >   v e h i c l e P t r ( 
                         n e w   V e h i c l e ( 
                                 a g e n t I d , 
                                 v e r t e x I d , 
                                 t h e A g e n t G i s P t r - > G e t V e r t e x ( v e r t e x I d ) , 
                                 r o a d I d , 
                                 l a n e N u m b e r , 
                                 t h i s ) ) ; 
 
                 s h a r e d _ p t r < A g e n t >   b u s D r i v e r P t r   =   A g e n t : : C r e a t e B u s D r i v e r A g e n t ( 
                         t h i s , 
                         a g e n t I d , 
                         ( * t h i s ) . G e t S i m E n g i n e I n t e r f a c e P t r ( a g e n t I d ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t P r o f i l e ( A G E N T _ T Y P E _ B U S ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t E m p t y T a s k T a b l e ( ) , 
                         t h e A g e n t G i s P t r , 
                         p u b l i c V e h i c l e T a b l e P t r , 
                         t h e R o u t e S e a r c h S u b s y s t e m P t r , 
                         v e h i c l e P t r , 
                         b u s N o d e P t r , 
                         b u s P t r ) ; 
 
                 ( * t h i s ) . A d d N o d e ( b u s N o d e P t r ) ; 
                 ( * t h i s ) . A d d A g e n t W i t h o u t N o d e G e n e r a t i o n ( b u s D r i v e r P t r ) ; 
 
                 b u s P t r - > S e t V e h i c l e ( v e h i c l e P t r ) ; 
 
                 b u s N o d e P t r - > S e t P u b l i c V e h i c l e ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         t h e A g e n t G i s P t r , 
                         ( * t h i s ) . C u r r e n t T i m e ( ) , 
                         b u s P t r ) ; 
 
                 t h e A g e n t G i s P t r - > A d d V e h i c l e ( v e h i c l e P t r ) ; 
 
                 b u s N o d e P t r s . p o p ( ) ; 
 
                 ( * t h i s ) . O u t p u t T r a c e ( " C r e a t e   B u s   "   +   C o n v e r t T o S t r i n g ( a g e n t I d ) ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : P r o f i l e V a l u e O u t p u t S u b s y s t e m : : R e c o r d A s s i g n e d P r o f i l e V a l u e s T o F i l e ( 
         c o n s t   A g e n t I d T y p e &   a g e n t I d , 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   p r o f i l e P t r , 
         c o n s t   m a p < s t r i n g ,   d o u b l e > &   a s s i g n e d V a l u e s , 
         c o n s t   b o o l   h a s C a r , 
         c o n s t   b o o l   h a s B i c y c l e ) 
 { 
         i f   ( ! p r o f i l e V a l u e O u t p u t F i l e . i s _ o p e n ( ) )   { 
                 r e t u r n ; 
         } 
 
         i f   ( a g e n t I d   = =   M A S T E R _ A N Y _ A G E N T _ I D )   { 
                 / /   S k i p   m a s t e r   a g e n t   p r o f i l e 
                 r e t u r n ; 
         } 
 
         t y p e d e f   m a p < s t r i n g ,   d o u b l e > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         i f   ( a g e n t I d   = =   M A S T E R _ B U S _ A G E N T _ I D )   { 
 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   " P r o f i l e T y p e : B u s "   < <   e n d l ; 
 
         }   e l s e   i f   ( a g e n t I d   = =   M A S T E R _ T A X I _ A G E N T _ I D )   { 
 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   " P r o f i l e T y p e : T a x i "   < <   e n d l ; 
 
         }   e l s e   { 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   " P r o f i l e T y p e : "   < <   a g e n t I d   < <   e n d l ; 
         } 
 
         f o r ( I t e r T y p e   i t e r   =   a s s i g n e d V a l u e s . b e g i n ( ) ; 
                 i t e r   ! =   a s s i g n e d V a l u e s . e n d ( ) ;   i t e r + + )   { 
 
                 c o n s t   s t r i n g &   p r o f i l e N a m e   =   ( * i t e r ) . f i r s t ; 
                 c o n s t   d o u b l e   v a l u e   =   ( * i t e r ) . s e c o n d ; 
 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   p r o f i l e N a m e   < <   "   =   "   < <   v a l u e   < <   e n d l ; 
         } 
 
         i f   ( ( a g e n t I d   ! =   M A S T E R _ B U S _ A G E N T _ I D )   & & 
                 ( a g e n t I d   ! =   M A S T E R _ T A X I _ A G E N T _ I D ) )   { 
 
                 d o u b l e   p r i v a t e C a r O w n e r s h i p   =   0 . 0 ; 
 
                 i f   ( h a s C a r )   { 
                         p r i v a t e C a r O w n e r s h i p   =   1 . 0 ; 
                 } 
 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ P R I V A T E _ C A R _ O W N E R S H I P ]   < <   "   =   "   < <   p r i v a t e C a r O w n e r s h i p   < <   e n d l ; 
 
                 d o u b l e   b i c y c l e O w n e r s h i p   =   0 . 0 ; 
 
                 i f   ( h a s B i c y c l e )   { 
                         b i c y c l e O w n e r s h i p   =   1 . 0 ; 
                 } 
 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ B I C Y C L E _ O W N E R S H I P ]   < <   "   =   "   < <   b i c y c l e O w n e r s h i p   < <   e n d l ; 
 
                 c o n s t   A g e n t M o b i l i t y C l a s s T y p e   m o b i l i t y C l a s s   =   p r o f i l e P t r - > G e t M o b i l i t y C l a s s ( ) ; 
 
                 p r o f i l e V a l u e O u t p u t F i l e   < <   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ W A L K _ S P E E D _ A T _ T R A N S F E R ]   < <   "   =   "   < <   G e t A g e n t M o b i l i t y C l a s s N a m e ( m o b i l i t y C l a s s )   < <   e n d l ; 
 
                 c o n s t   A g e n t V a l u e F o r m u l a &   u t i l i t y F o r m u l a 1   =   p r o f i l e P t r - > G e t U t i l i t y F o r m u l a 1 ( ) ; 
                 c o n s t   A g e n t V a l u e F o r m u l a &   u t i l i t y F o r m u l a 2   =   p r o f i l e P t r - > G e t U t i l i t y F o r m u l a 2 ( ) ; 
 
                 i f   ( ! u t i l i t y F o r m u l a 1 . I s N u l l ( ) )   { 
                         p r o f i l e V a l u e O u t p u t F i l e   < <   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ U T I L I T Y 1 _ F U N C T I O N ]   < <   "   =   "   < <   u t i l i t y F o r m u l a 1 . G e t I n p u t F o r m u l a S t r i n g ( )   < <   e n d l ; 
                 } 
                 i f   ( ! u t i l i t y F o r m u l a 2 . I s N u l l ( ) )   { 
                         p r o f i l e V a l u e O u t p u t F i l e   < <   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ U T I L I T Y 2 _ F U N C T I O N ]   < <   "   =   "   < <   u t i l i t y F o r m u l a 2 . G e t I n p u t F o r m u l a S t r i n g ( )   < <   e n d l ; 
                 } 
         } 
 
         p r o f i l e V a l u e O u t p u t F i l e   < <   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ R O U T E _ P R I O R I T Y ]   < <   "   =   "   < <   p r o f i l e P t r - > G e t P r i m a r y R o u t e C o s t F o r m u l a ( ) . G e t I n p u t F o r m u l a S t r i n g ( )   < <   e n d l ; 
 
         p r o f i l e V a l u e O u t p u t F i l e   < <   e n d l ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d C a r ( ) 
 { 
         q u e u e < s h a r e d _ p t r < V e h i c l e N o d e >   > &   v e h i c l e N o d e P t r s   =   r e s e r v e d V e h i c l e N o d e P t r s . a t ( V E H I C L E _ C A R ) ; 
 
         l i s t < s h a r e d _ p t r < V e h i c l e >   > &   v e h i c l e P t r s   =   n e w l y A d d e d V e h i c l e P t r s ; 
 
         t y p e d e f   l i s t < s h a r e d _ p t r < V e h i c l e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   v e h i c l e P t r s . b e g i n ( ) ;   i t e r   ! =   v e h i c l e P t r s . e n d ( ) ;   i t e r + + )   { 
                 c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r   =   ( * i t e r ) ; 
 
                 i f   ( v e h i c l e N o d e P t r s . e m p t y ( ) )   { 
                         c e r r   < <   " E r r o r :   n o t   e n o u g h   v e h i c l e   n o d e "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r   =   v e h i c l e N o d e P t r s . f r o n t ( ) ; 
 
                 v e h i c l e N o d e P t r - > S e t V e h i c l e ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         t h e A g e n t G i s P t r , 
                         ( * t h i s ) . C u r r e n t T i m e ( ) , 
                         v e h i c l e P t r ) ; 
 
                 ( * t h i s ) . A d d N o d e ( v e h i c l e N o d e P t r ) ; 
 
                 v e h i c l e N o d e P t r s . p o p ( ) ; 
 
                 t h e A g e n t G i s P t r - > A d d V e h i c l e ( v e h i c l e P t r ) ; 
         } 
         v e h i c l e P t r s . c l e a r ( ) ; 
 } 
 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d T a x i ( c o n s t   s h a r e d _ p t r < T a x i > &   t a x i P t r ) 
 { 
         c o n s t   A g e n t I d T y p e   a g e n t I d   =   t a x i P t r - > G e t D r i v e r A g e n t I d ( ) ; 
 
         c o n s t   s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r   = 
                 ( * t h i s ) . C r e a t e V e h i c l e N o d e ( a g e n t I d ,   V E H I C L E _ T A X I ) ; 
 
         c o n s t   s h a r e d _ p t r < A g e n t >   t a x i D r i v e r P t r   = 
                 A g e n t : : C r e a t e T a x i D r i v e r A g e n t ( 
                         t h i s , 
                         a g e n t I d , 
                         ( * t h i s ) . G e t S i m E n g i n e I n t e r f a c e P t r ( a g e n t I d ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t P r o f i l e ( A G E N T _ T Y P E _ T A X I ) , 
                         p r o f i l e A n d T a s k T a b l e P t r - > G e t E m p t y T a s k T a b l e ( ) , 
                         t h e A g e n t G i s P t r , 
                         p u b l i c V e h i c l e T a b l e P t r , 
                         t h e R o u t e S e a r c h S u b s y s t e m P t r , 
                         v e h i c l e N o d e P t r , 
                         t a x i P t r ) ; 
 
         ( * t h i s ) . A d d N o d e ( v e h i c l e N o d e P t r ) ; 
         ( * t h i s ) . A d d A g e n t W i t h o u t N o d e G e n e r a t i o n ( t a x i D r i v e r P t r ) ; 
 
         v e h i c l e N o d e P t r - > S e t T a x i ( 
                 * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                 t h e A g e n t G i s P t r , 
                 ( * t h i s ) . C u r r e n t T i m e ( ) , 
                 t a x i P t r ) ; 
 
         t h e A g e n t G i s P t r - > A d d V e h i c l e ( t a x i P t r ) ; 
 } 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d C o m m u n i c a t i o n N o d e ( c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   a N o d e P t r ) 
 { 
         c o n s t   A g e n t I d T y p e   a g e n t I d   =   a N o d e P t r - > G e t N o d e I d ( ) ; 
 
         i f   ( e n t i r e A g e n t I d s . f i n d ( a g e n t I d )   = =   e n t i r e A g e n t I d s . e n d ( ) )   { 
 
                 ( * t h i s ) . A d d N o d e ( a N o d e P t r ) ; 
 
         }   e l s e   { 
 
                 s y n c h r o n i z e d N o d e P t r s [ a g e n t I d ]   =   a N o d e P t r ; 
 
                 ( * t h i s ) . A t t a c h C o m m u n i c a t i o n N o d e ( a g e n t I d ,   a N o d e P t r ) ; 
         } 
 } 
 
 b o o l   M u l t i A g e n t S i m u l a t o r : : I s E q u a l T o A g e n t I d ( c o n s t   N o d e I d &   t h e N o d e I d )   c o n s t 
 { 
         r e t u r n   ( e n t i r e A g e n t I d s . f i n d ( t h e N o d e I d )   ! =   e n t i r e A g e n t I d s . e n d ( ) ) ; 
 } 
 
 S i m T i m e   M u l t i A g e n t S i m u l a t o r : : G e t W a k e u p T i m e ( c o n s t   N o d e I d &   t h e N o d e I d )   c o n s t 
 { 
         a s s e r t ( ( * t h i s ) . I s E q u a l T o A g e n t I d ( t h e N o d e I d ) ) ; 
 
         t y p e d e f   m a p < N o d e I d ,   S i m T i m e > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   w a k e u p T i m e s . f i n d ( t h e N o d e I d ) ; 
 
         a s s e r t ( i t e r   ! =   w a k e u p T i m e s . e n d ( ) ) ; 
 
         r e t u r n   ( * i t e r ) . s e c o n d ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A d d A g e n t ( 
         c o n s t   s h a r e d _ p t r < A g e n t > &   a g e n t P t r , 
         c o n s t   b o o l   w i t h N o d e G e n e r a t i o n ) 
 { 
         A g e n t R e s o u r c e   r e s o u r c e ( a g e n t P t r ) ; 
         c o n s t   A g e n t I d T y p e   a g e n t I d   =   r e s o u r c e . A g e n t I d ( ) ; 
 
         c o u t   < <   " A g e n t I D   :   "   < <   r e s o u r c e . A g e n t I d ( )   < <   e n d l ; 
         A d d A g e n t s [ r e s o u r c e . A g e n t I d ( )   -   1 ]   =   r e s o u r c e ; 
 
         c o u t   < <   " A d d A g e n t s   I d   i s   "   < <   A d d A g e n t s [ r e s o u r c e . A g e n t I d ( )   -   1 ] . A g e n t I d ( )   < <   e n d l ; 
 
         i f   ( w i t h N o d e G e n e r a t i o n ) { 
                 c o u t   < <   " N o d e   G e n e r a t e d "   < <   e n d l ; 
         }   e l s e   { 
                 c o u t   < <   " N o t   G e n e r a t e d "   < <   e n d l ; 
         } 
 
         / /   m u l t i a g e n t 
 
         i t e r T o A g e n t L i s t [ a g e n t I d ]   =   a g e n t P t r s . i n s e r t ( a g e n t P t r s . e n d ( ) ,   a g e n t P t r ) ; 
 
         n e w l y A d d e d A g e n t I d s . i n s e r t ( a g e n t I d ) ; 
 
         / /   s i m 
         i f   ( w i t h N o d e G e n e r a t i o n )   { 
                 s h a r e d _ p t r < N e t w o r k N o d e >   s i m N o d e P t r ; 
 
                 i f   ( c r e a t e C o m m u n i c a t i o n N o d e A t W a k e u p T i m e F o r . f i n d ( a g e n t I d )   ! =   c r e a t e C o m m u n i c a t i o n N o d e A t W a k e u p T i m e F o r . e n d ( ) )   { 
                         ( * t h i s ) . C r e a t e N e w N o d e ( * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ,   a g e n t I d ,   a g e n t P t r - > G e t M o b i l i t y M o d e l P t r ( ) ) ; 
                 } 
 
                 i f   ( s y n c h r o n i z e d N o d e P t r s . f i n d ( a g e n t I d )   ! =   s y n c h r o n i z e d N o d e P t r s . e n d ( ) )   { 
 
                         s i m N o d e P t r   =   s y n c h r o n i z e d N o d e P t r s [ a g e n t I d ] ; 
                         s y n c h r o n i z e d N o d e P t r s . e r a s e ( a g e n t I d ) ; 
 
                 }   e l s e   { 
                         s i m N o d e P t r . r e s e t ( 
                                 n e w   A g e n t N o d e ( 
                                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                                         t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                                         t h e G i s S u b s y s t e m P t r , 
                                         a g e n t P t r - > G e t S i m E n g i n e I n t e r f a c e P t r ( ) , 
                                         a g e n t I d , 
                                         r u n S e e d , 
                                         a g e n t P t r - > G e t M o b i l i t y M o d e l P t r ( ) , 
                                         r e s o u r c e ) ) ; 
                 } 
 
                 ( * t h i s ) . A d d N o d e ( s i m N o d e P t r ) ; 
         } 
 
         c o n s t   G i s P o s i t i o n I d T y p e   f i r s t P o s i t i o n I d   =   r e s o u r c e . G e t C u r r e n t P o s i t i o n I d ( ) ; 
         r e s o u r c e . S e t C u r r e n t P o s i t i o n I d ( I n v a l i d G i s P o s i t i o n I d ) ; 
         r e s o u r c e . S e t D e s i r e d N e x t P o s i t i o n I d ( f i r s t P o s i t i o n I d ) ; 
 
         t h e A g e n t G i s P t r - > U p d a t e P e o p l e T r a n s l a t i o n B e t w e e n G i s O b j e c t s ( 
                 r e s o u r c e , 
                 r e s o u r c e . G e t C u r r e n t P o s i t i o n I d ( ) , 
                 r e s o u r c e . G e t C u r r e n t P o s i t i o n I d ( ) , 
                 r e s o u r c e . G e t D e s i r e d P o s i t i o n I d ( ) , 
                 A G E N T _ B E H A V I O R _ N O T H I N G , 
                 A G E N T _ B E H A V I O R _ N O T H I N G ) ; 
 
         r e s o u r c e . A r r i v e d A t G i s P o s i t i o n N o t i f i c a t i o n ( ) ; 
 
         t y p e d e f   m a p < A g e n t I d T y p e ,   l i s t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   >   > : : i t e r a t o r   C o m m u n i c a t i o n N o d e s I t e r ; 
 
         C o m m u n i c a t i o n N o d e s I t e r   c o m m u n i c a t i o n N o d e s I t e r   =   c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n . f i n d ( a g e n t I d ) ; 
 
         i f   ( c o m m u n i c a t i o n N o d e s I t e r   ! =   c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n . e n d ( ) )   { 
                 l i s t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > &   c o m m u n i c a t i o n N o d e P t r s   =   ( * c o m m u n i c a t i o n N o d e s I t e r ) . s e c o n d ; 
 
                 t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   > : : i t e r a t o r   N o d e I t e r ; 
 
                 f o r ( N o d e I t e r   n o d e I t e r   =   c o m m u n i c a t i o n N o d e P t r s . b e g i n ( ) ; 
                         n o d e I t e r   ! =   c o m m u n i c a t i o n N o d e P t r s . e n d ( ) ;   n o d e I t e r + + )   { 
 
                         a g e n t P t r - > A d d C o m m u n i c a t i o n N o d e ( * n o d e I t e r ) ; 
                 } 
 
                 c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n . e r a s e ( a g e n t I d ) ; 
         } 
 
 
         ( * t h i s ) . O u t p u t T r a c e ( " A d d   A g e n t   "   +   C o n v e r t T o S t r i n g ( a g e n t I d ) ) ; 
 } 
 
 s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e >   M u l t i A g e n t S i m u l a t o r : : G e t S i m E n g i n e I n t e r f a c e P t r ( c o n s t   A g e n t I d T y p e &   a g e n t I d ) 
 { 
         u n s i g n e d   i n t   p a r t i t i o n I n d e x   =   0 ; 
         i f   ( t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > P a r a m e t e r E x i s t s ( 
                         " p a r a l l e l i z a t i o n - p a r t i t i o n - i n d e x " ,   a g e n t I d ) )   { 
                 p a r t i t i o n I n d e x   = 
                         ( t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d N o n N e g a t i v e I n t ( 
                                 " p a r a l l e l i z a t i o n - p a r t i t i o n - i n d e x " ,   a g e n t I d )   % 
                           t h e S i m u l a t i o n E n g i n e P t r - > G e t N u m b e r P a r t i t i o n T h r e a d s ( ) ) ; 
         } 
 
         r e t u r n   t h e S i m u l a t i o n E n g i n e P t r - > G e t S i m u l a t i o n E n g i n e I n t e r f a c e ( 
                 * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ,   a g e n t I d ,   p a r t i t i o n I n d e x ) ; 
 } 
 
 s h a r e d _ p t r < V e h i c l e N o d e >   M u l t i A g e n t S i m u l a t o r : : C r e a t e V e h i c l e N o d e ( 
         c o n s t   A g e n t I d T y p e &   a g e n t I d , 
         c o n s t   V e h i c l e T y p e &   v e h i c l e T y p e ) 
 { 
         u n s i g n e d   i n t   p a r t i t i o n I n d e x   =   0 ; 
 
         i f   ( t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > P a r a m e t e r E x i s t s ( 
                         " p a r a l l e l i z a t i o n - p a r t i t i o n - i n d e x " ,   a g e n t I d ) )   { 
                 p a r t i t i o n I n d e x   = 
                         ( t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > R e a d N o n N e g a t i v e I n t ( 
                                 " p a r a l l e l i z a t i o n - p a r t i t i o n - i n d e x " ,   a g e n t I d )   % 
                           t h e S i m u l a t i o n E n g i n e P t r - > G e t N u m b e r P a r t i t i o n T h r e a d s ( ) ) ; 
         } 
 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   s i m E n g i n e I n t e r f a c e P t r   = 
                 t h e S i m u l a t i o n E n g i n e P t r - > G e t S i m u l a t i o n E n g i n e I n t e r f a c e ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ,   a g e n t I d ,   p a r t i t i o n I n d e x ) ; 
 
         s h a r e d _ p t r < V e h i c l e M o b i l i t y M o d e l >   m o b i l i t y M o d e l P t r ( n e w   V e h i c l e M o b i l i t y M o d e l ( a g e n t I d ) ) ; 
 
         s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r ( 
                 n e w   V e h i c l e N o d e ( 
                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                         t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                         t h e G i s S u b s y s t e m P t r , 
                         s i m E n g i n e I n t e r f a c e P t r , 
                         a g e n t I d , 
                         r u n S e e d , 
                         m o b i l i t y M o d e l P t r ) ) ; 
 
         r e t u r n   v e h i c l e N o d e P t r ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : R e s e r v e V e h i c l e N o d e ( 
         c o n s t   A g e n t I d T y p e &   a g e n t I d , 
         c o n s t   V e h i c l e T y p e &   v e h i c l e T y p e ) 
 { 
         c o n s t   s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r   = 
                 ( * t h i s ) . C r e a t e V e h i c l e N o d e ( a g e n t I d ,   v e h i c l e T y p e ) ; 
 
         r e s e r v e d V e h i c l e N o d e P t r s . a t ( v e h i c l e T y p e ) . p u s h ( v e h i c l e N o d e P t r ) ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : S e t O w n e r A g e n t ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         c o n s t   A g e n t I d T y p e &   o w n e r A g e n t I d ) 
 { 
         a s s e r t ( r e s o u r c e . A g e n t I d ( )   ! =   o w n e r A g e n t I d ) ; 
 
         o w n e r C h a n g e E v e n t s [ r e s o u r c e . A g e n t I d ( ) ]   =   O w n e r C h a n g e E v e n t ( r e s o u r c e . A g e n t I d ( ) ,   o w n e r A g e n t I d ) ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : R e m o v e O w n e r A g e n t C h a n g e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e ) 
 { 
         o w n e r C h a n g e E v e n t s . e r a s e ( r e s o u r c e . A g e n t I d ( ) ) ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : C h a n g e A g e n t O w n e r I f N e c e s s a r y ( ) 
 { 
         l i s t < p a i r < A g e n t I d T y p e ,   s h a r e d _ p t r < A g e n t >   >   >   f r e e A g e n t P t r s ; 
 
         t y p e d e f   m a p < A g e n t I d T y p e ,   O w n e r C h a n g e E v e n t > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   o w n e r C h a n g e E v e n t s . b e g i n ( ) ; 
                 i t e r   ! =   o w n e r C h a n g e E v e n t s . e n d ( ) ;   i t e r + + )   { 
 
                 c o n s t   O w n e r C h a n g e E v e n t &   o w n e r C h a n g e E v e n t   =   ( * i t e r ) . s e c o n d ; 
 
                 a s s e r t ( i t e r T o A g e n t L i s t . f i n d ( o w n e r C h a n g e E v e n t . a g e n t I d )   ! =   i t e r T o A g e n t L i s t . e n d ( ) ) ; 
 
                 t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r   A g e n t I t e r ; 
 
                 A g e n t I t e r   c h i l d I t e r   =   i t e r T o A g e n t L i s t [ o w n e r C h a n g e E v e n t . a g e n t I d ] ; 
 
                 c o n s t   s h a r e d _ p t r < A g e n t >   c h i l d A g e n t P t r   =   ( * c h i l d I t e r ) ; 
 
                 i f   ( o w n e r C h a n g e E v e n t . o w n e r I d   = =   M A S T E R _ A N Y _ A G E N T _ I D )   { 
                         a s s e r t ( c h i l d A g e n t P t r - > H a s P a r e n t ( ) ) ; 
 
                         A g e n t I t e r   p a r e n t I t e r   =   i t e r T o A g e n t L i s t [ c h i l d A g e n t P t r - > p a r e n t A g e n t I d ] ; 
                         c o n s t   s h a r e d _ p t r < A g e n t >   p a r e n t A g e n t P t r   =   ( * p a r e n t I t e r ) ; 
 
                         p a r e n t A g e n t P t r - > c h i l d A g e n t P t r s . e r a s e ( c h i l d I t e r ) ; 
 
                 }   e l s e   { 
                         a s s e r t ( ! c h i l d A g e n t P t r - > H a s P a r e n t ( ) ) ; 
 
                         a g e n t P t r s . e r a s e ( c h i l d I t e r ) ; 
                 } 
 
                 f r e e A g e n t P t r s . p u s h _ b a c k ( m a k e _ p a i r ( o w n e r C h a n g e E v e n t . o w n e r I d ,   c h i l d A g e n t P t r ) ) ; 
 
                 i t e r T o A g e n t L i s t . e r a s e ( o w n e r C h a n g e E v e n t . a g e n t I d ) ; 
         } 
 
         o w n e r C h a n g e E v e n t s . c l e a r ( ) ; 
 
         t y p e d e f   l i s t < p a i r < A g e n t I d T y p e ,   s h a r e d _ p t r < A g e n t >   >   > : : c o n s t _ i t e r a t o r   I t e r T y p e 2 ; 
 
         f o r ( I t e r T y p e 2   i t e r   =   f r e e A g e n t P t r s . b e g i n ( ) ;   i t e r   ! =   f r e e A g e n t P t r s . e n d ( ) ;   i t e r + + )   { 
                 c o n s t   A g e n t I d T y p e &   o w n e r A g e n t I d   =   ( * i t e r ) . f i r s t ; 
                 c o n s t   s h a r e d _ p t r < A g e n t > &   a g e n t P t r   =   ( * i t e r ) . s e c o n d ; 
                 c o n s t   A g e n t I d T y p e   a g e n t I d   =   a g e n t P t r - > G e t A g e n t I d ( ) ; 
 
                 a g e n t P t r - > p a r e n t A g e n t I d   =   o w n e r A g e n t I d ; 
 
                 i f   ( o w n e r A g e n t I d   = =   M A S T E R _ A N Y _ A G E N T _ I D )   { 
 
                         i t e r T o A g e n t L i s t [ a g e n t I d ]   =   a g e n t P t r s . i n s e r t ( a g e n t P t r s . e n d ( ) ,   a g e n t P t r ) ; 
                 } 
                 e l s e   { 
                         l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r   l i s t I t e r   =   i t e r T o A g e n t L i s t [ o w n e r A g e n t I d ] ; 
                         s h a r e d _ p t r < A g e n t >   o w n e r A g e n t P t r   =   ( * l i s t I t e r ) ; 
                         l i s t < s h a r e d _ p t r < A g e n t >   > &   c h i l d A g e n t P t r s   =   o w n e r A g e n t P t r - > c h i l d A g e n t P t r s ; 
 
                         i t e r T o A g e n t L i s t [ a g e n t I d ]   =   c h i l d A g e n t P t r s . i n s e r t ( c h i l d A g e n t P t r s . e n d ( ) ,   a g e n t P t r ) ; 
                 } 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : D e l e t e I n a c t i v e A g e n t s ( ) 
 { 
         w h i l e   ( ! d e l e t e N o d e I d s . e m p t y ( ) )   { 
                 c o n s t   A g e n t I d T y p e   a g e n t I d   =   d e l e t e N o d e I d s . f r o n t ( ) ; 
 
                 t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r   A g e n t I t e r ; 
 
                 i f   ( i s D e b u g M o d e )   { 
                         c o u t   < <   " d e l e t e   a g e n t   "   < <   a g e n t I d   < <   e n d l ; 
                 } 
 
                 A g e n t I t e r   a g e n t I t e r   =   i t e r T o A g e n t L i s t [ a g e n t I d ] ; 
                 s h a r e d _ p t r < A g e n t >   a g e n t P t r   =   ( * a g e n t I t e r ) ; 
 
                 i f   ( ! a g e n t P t r - > H a s P a r e n t ( ) )   { 
                         a g e n t P t r s . e r a s e ( a g e n t I t e r ) ; 
                 }   e l s e   { 
 
                         i f   ( i t e r T o A g e n t L i s t . f i n d ( a g e n t P t r - > p a r e n t A g e n t I d )   ! =   i t e r T o A g e n t L i s t . e n d ( ) )   { 
                                 A g e n t I t e r   p a r e n t I t e r   =   i t e r T o A g e n t L i s t [ a g e n t P t r - > p a r e n t A g e n t I d ] ; 
                                 s h a r e d _ p t r < A g e n t >   p a r e n t A g e n t P t r   =   ( * p a r e n t I t e r ) ; 
 
                                 p a r e n t A g e n t P t r - > c h i l d A g e n t P t r s . e r a s e ( a g e n t I t e r ) ; 
                         } 
                 } 
 
                 a s s e r t ( a g e n t P t r - > c h i l d A g e n t P t r s . e m p t y ( ) ) ; 
 
                 i t e r T o A g e n t L i s t . e r a s e ( a g e n t I d ) ; 
 
                 d e l e t e N o d e I d s . p o p ( ) ; 
 
                 ( * t h i s ) . D e l e t e N o d e ( a g e n t I d ) ; 
 
                 i f   ( a g e n t P t r - > v e h i c l e N o d e P t r   ! = n u l l p t r )   { 
                         s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r   =   a g e n t P t r - > v e h i c l e N o d e P t r ; 
 
                         r e s e r v e d V e h i c l e N o d e P t r s . a t ( v e h i c l e N o d e P t r - > G e t V e h i c l e T y p e ( ) ) . p u s h ( v e h i c l e N o d e P t r ) ; 
                 } 
         } 
 } 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : I n c r e m e n t T i m e S t e p ( ) 
 { 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : c o n s t _ i t e r a t o r   A g e n t I t e r ; 
 
 
         i f   ( i s S i m u l a t i o n D o n e )   { 
                 r e t u r n ; 
         } 
 
         t h e A g e n t G i s P t r - > E x e c u t e A c t i o n s F o r C u r r e n t T i m e s t e p ( ) ; 
         ( * t h i s ) . S y n c A p p l i c a t i o n C r e a t i o n ( ) ; 
 
         / /   D e l a y i n g   d e l e t i o n   u n t i l   s y n c h r o n i z a t i o n   o f   a l l   a g e n t s   h a s   b e e n   d o n e . 
 
         ( * t h i s ) . D e l e t e I n a c t i v e A g e n t s ( ) ; 
 
         / /   m a i n   r o u t i n e 
         f o r ( A g e n t I t e r   i t e r   =   a g e n t P t r s . b e g i n ( ) ;   i t e r   ! =   a g e n t P t r s . e n d ( ) ;   i t e r + + )   { 
 
                 A g e n t &   a g e n t   =   * ( * i t e r ) ; 
 
                 a g e n t . I n c r e m e n t T i m e ( ) ; 
 
                 i f   ( a g e n t . I s D e l e t e d A f t e r E n d O f T i m e S t e p ( ) )   { 
 
                         c o n s t   A g e n t I d T y p e &   a g e n t I d   =   a g e n t . G e t A g e n t I d ( ) ; 
                         i f   ( n e w l y A d d e d A g e n t I d s . f i n d ( a g e n t I d )   = =   n e w l y A d d e d A g e n t I d s . e n d ( ) )   { 
                                 d e l e t e N o d e I d s . p u s h ( a g e n t I d ) ; 
                         } 
                 } 
         } 
 
         / /   i n c r e m e n t   a t   t h e   e n d   o f   t i m e   s t e p   f o r   G U I   s t e p   c o m p a t i b i l i t y . 
         c u r r e n t S n a p s h o t I d   =   ( c u r r e n t S n a p s h o t I d   +   1 )   %   N U M B E R _ T I M E S T E P _ S N A P S H O T S ; 
 } 
 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : R e r o u t e A l l A g e n t s ( ) 
 { 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : c o n s t _ i t e r a t o r   A g e n t I t e r ; 
 
         f o r ( A g e n t I t e r   i t e r   =   a g e n t P t r s . b e g i n ( ) ;   i t e r   ! =   a g e n t P t r s . e n d ( ) ;   i t e r + + )   { 
                 A g e n t &   a g e n t   =   * ( * i t e r ) ; 
 
                 a g e n t . R e c a l c u l a t e R o u t e ( c u r r e n t T i m e ) ; 
         } 
 } 
 
 s t a t i c   c o n s t   G i s O b j e c t I d T y p e   M I N I M U M _ G I S _ O B J E C T _ I D   =   1 0 0 0 0 0 0 0 0 ; 
 
 v o i d   A g e n t : : O u t p u t T r a c e E v e n t ( ) 
 { 
         i f   ( s i m E n g i n e I n t e r f a c e P t r   ! =   n u l l p t r   & & 
                 s i m E n g i n e I n t e r f a c e P t r - > T r a c e I s O n ( T r a c e M a s ) )   { 
 
                 i f   ( u t i l i t y 1 T r a c e . H a s C h a n g e d ( ) )   { 
                         s i m u l a t o r P t r - > O u t p u t T r a c e E v e n t ( a g e n t I d ,   " U t i l i t y 1 " ,   u t i l i t y 1 T r a c e . G e t V a l u e A n d U n s e t C h a n g e F l a g ( ) ) ; 
                 } 
                 i f   ( u t i l i t y 2 T r a c e . H a s C h a n g e d ( ) )   { 
                         s i m u l a t o r P t r - > O u t p u t T r a c e E v e n t ( a g e n t I d ,   " U t i l i t y 2 "   ,   u t i l i t y 2 T r a c e . G e t V a l u e A n d U n s e t C h a n g e F l a g ( ) ) ; 
                 } 
                 i f   ( t r a v e l D i s t a n c e T r a c e . H a s C h a n g e d ( ) )   { 
                         s i m u l a t o r P t r - > O u t p u t T r a c e E v e n t ( a g e n t I d ,   " T r a v e l D i s t a n c e "   ,   t r a v e l D i s t a n c e T r a c e . G e t V a l u e A n d U n s e t C h a n g e F l a g ( ) ) ; 
                 } 
                 i f   ( t r a v e l T i m e T r a c e . H a s C h a n g e d ( ) )   { 
                         s i m u l a t o r P t r - > O u t p u t T r a c e E v e n t ( a g e n t I d ,   " T r a v e l T i m e "   ,   t r a v e l T i m e T r a c e . G e t V a l u e A n d U n s e t C h a n g e F l a g ( ) ) ; 
                 } 
                 i f   ( d e s t i n a t i o n C h a n g e T r a c e . H a s C h a n g e d ( )   & & 
                         d e s t P o s i t i o n I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
                         s i m u l a t o r P t r - > O u t p u t T r a c e E v e n t ( a g e n t I d ,   " D e s t i n a t i o n C h a n g e C o u n t "   ,   s t a t i c _ c a s t < d o u b l e > ( d e s t i n a t i o n C h a n g e T r a c e . G e t V a l u e A n d U n s e t C h a n g e F l a g ( ) ) ) ; 
 
                         c o n s t   G i s S u b s y s t e m &   s u b s y s t e m   =   t h e A g e n t G i s P t r - > G e t S u b s y s t e m ( ) ; 
                         c o n s t   s t r i n g   n a m e   =   s u b s y s t e m . G e t G i s O b j e c t ( d e s t P o s i t i o n I d ) . G e t O b j e c t N a m e ( ) ; 
 
                         s i m u l a t o r P t r - > O u t p u t S t r i n g T r a c e E v e n t ( a g e n t I d ,   " D e s t i n a t i o n "   ,   n a m e ) ; 
                 } 
                 i f   ( d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e . H a s C h a n g e d ( )   & & 
                         d e s t P o s i t i o n I d   ! =   U N R E A C H A B L E _ P O S I T I O N _ I D )   { 
 
                         s i m u l a t o r P t r - > O u t p u t T r a c e E v e n t ( a g e n t I d ,   " D e s t i n a t i o n C h a n g e C o u n t B y C o m m u n i c a t i o n "   ,   s t a t i c _ c a s t < d o u b l e > ( d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e . G e t V a l u e A n d U n s e t C h a n g e F l a g ( ) ) ) ; 
                 } 
         } 
 } 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O u t p u t T r a c e E v e n t ( 
         c o n s t   N o d e I d &   g i s O b j e c t O r A g e n t I d , 
         c o n s t   s t r i n g &   e v e n t N a m e , 
         c o n s t   d o u b l e   v a l u e )   c o n s t 
 { 
         T r a c e S u b s y s t e m &   t r a c e S u b s y s t e m   =   t h e S i m u l a t i o n E n g i n e P t r - > G e t T r a c e S u b s y s t e m ( ) ; 
 
         i f   ( t r a c e S u b s y s t e m . B i n a r y O u t p u t I s O n ( ) )   { 
 
                 c o n s t   M u l t i A g e n t T r a c e R e c o r d   r e c o r d ( v a l u e ) ; 
 
                 t r a c e S u b s y s t e m . O u t p u t T r a c e I n B i n a r y ( 
                         c u r r e n t T i m e , 
                         g i s O b j e c t O r A g e n t I d , 
                         m o d e l N a m e , 
                         " " , 
                         e v e n t N a m e , 
                         r e i n t e r p r e t _ c a s t < c o n s t   u n s i g n e d   c h a r *   > ( & r e c o r d ) , 
                         s i z e o f ( r e c o r d ) , 
                         M A S T E R _ T H R E A D _ N U M B E R ) ; 
 
         }   e l s e   { 
 
                 o s t r i n g s t r e a m   o u t S t r e a m ; 
                 o u t S t r e a m   < <   " V =   "   < <   v a l u e ; 
 
                 t r a c e S u b s y s t e m . O u t p u t T r a c e ( 
                         c u r r e n t T i m e , 
                         g i s O b j e c t O r A g e n t I d , 
                         m o d e l N a m e , 
                         " " , 
                         e v e n t N a m e , 
                         o u t S t r e a m . s t r ( ) , 
                         M A S T E R _ T H R E A D _ N U M B E R ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O u t p u t S t r i n g T r a c e E v e n t ( 
         c o n s t   N o d e I d &   g i s O b j e c t O r A g e n t I d , 
         c o n s t   s t r i n g &   e v e n t N a m e , 
         c o n s t   s t r i n g &   v a l u e )   c o n s t 
 { 
         T r a c e S u b s y s t e m &   t r a c e S u b s y s t e m   =   t h e S i m u l a t i o n E n g i n e P t r - > G e t T r a c e S u b s y s t e m ( ) ; 
 
         i f   ( t r a c e S u b s y s t e m . B i n a r y O u t p u t I s O n ( ) )   { 
                 S t a t e T r a c e R e c o r d   r e c o r d ; 
 
                 c o n s t   s i z e _ t   n a m e S i z e   =   s t d : : m i n ( v a l u e . s i z e ( ) ,   s i z e o f ( r e c o r d . s t a t e I d )   -   1 ) ; 
 
                 f o r ( s i z e _ t   i   =   0 ;   i   <   n a m e S i z e ;   i + + )   { 
                         r e c o r d . s t a t e I d [ i ]   =   v a l u e [ i ] ; 
                 } 
                 r e c o r d . s t a t e I d [ n a m e S i z e ]   =   ' \ 0 ' ; 
 
                 t r a c e S u b s y s t e m . O u t p u t T r a c e I n B i n a r y ( 
                         c u r r e n t T i m e , 
                         g i s O b j e c t O r A g e n t I d , 
                         m o d e l N a m e , 
                         " " , 
                         e v e n t N a m e , 
                         r e i n t e r p r e t _ c a s t < c o n s t   u n s i g n e d   c h a r *   > ( & r e c o r d ) , 
                         s i z e o f ( r e c o r d ) , 
                         M A S T E R _ T H R E A D _ N U M B E R ) ; 
 
         }   e l s e   { 
 
                 o s t r i n g s t r e a m   o u t S t r e a m ; 
                 o u t S t r e a m   < <   " V =   "   < <   v a l u e ; 
 
                 t r a c e S u b s y s t e m . O u t p u t T r a c e ( 
                         c u r r e n t T i m e , 
                         g i s O b j e c t O r A g e n t I d , 
                         m o d e l N a m e , 
                         " " , 
                         e v e n t N a m e , 
                         o u t S t r e a m . s t r ( ) , 
                         M A S T E R _ T H R E A D _ N U M B E R ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : A t t a c h C o m m u n i c a t i o n N o d e ( 
         c o n s t   A g e n t I d T y p e &   a g e n t I d , 
         c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) 
 { 
         b o o l   f o u n d   =   f a l s e ; 
 
         t y p e d e f   m a p < A g e n t I d T y p e ,   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   i t e r T o A g e n t L i s t . f i n d ( a g e n t I d ) ; 
 
         i f   ( i t e r   ! =   i t e r T o A g e n t L i s t . e n d ( ) )   { 
                 ( * ( * i t e r ) . s e c o n d ) - > A d d C o m m u n i c a t i o n N o d e ( c o m m u n i c a t i o n N o d e P t r ) ; 
                 f o u n d   =   t r u e ; 
         } 
 
         i f   ( ! f o u n d )   { 
                 c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n [ a g e n t I d ] . p u s h _ b a c k ( c o m m u n i c a t i o n N o d e P t r ) ; 
         } 
 } 
 
 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : D e t a c h C o m m u n i c a t i o n N o d e ( 
         c o n s t   A g e n t I d T y p e &   a g e n t I d , 
         c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) 
 { 
         b o o l   f o u n d   =   f a l s e ; 
 
         t y p e d e f   m a p < A g e n t I d T y p e ,   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   i t e r T o A g e n t L i s t . f i n d ( a g e n t I d ) ; 
 
         i f   ( i t e r   ! =   i t e r T o A g e n t L i s t . e n d ( ) )   { 
                 ( * ( * i t e r ) . s e c o n d ) - > D e l e t e C o m m u n i c a t i o n N o d e ( c o m m u n i c a t i o n N o d e P t r ) ; 
                 f o u n d   =   t r u e ; 
         } 
 
         i f   ( ! f o u n d )   { 
                 c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n [ a g e n t I d ] . r e m o v e ( c o m m u n i c a t i o n N o d e P t r ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O u t p u t A g e n t T r a c e s ( ) 
 { 
         ( * t h i s ) . O u t p u t T r a c e F o r A l l N o d e P o s i t i o n s ( Z E R O _ T I M E ) ; 
 
         t y p e d e f   l i s t < s h a r e d _ p t r < A g e n t >   > : : c o n s t _ i t e r a t o r   A g e n t I t e r ; 
 
         f o r ( A g e n t I t e r   i t e r   =   a g e n t P t r s . b e g i n ( ) ;   i t e r   ! =   a g e n t P t r s . e n d ( ) ;   i t e r + + )   { 
                 ( * i t e r ) - > O u t p u t T r a c e E v e n t ( ) ; 
         } 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : C r e a t e A p p l i c a t i o n F o r N o d e ( 
         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
         c o n s t   N o d e I d &   s o u r c e N o d e I d , 
         c o n s t   I n t e r f a c e O r I n s t a n c e I d &   i n s t a n c e I d , 
         c o n s t   v e c t o r < s t r i n g > &   p a r a m e t e r L i n e s , 
         c o n s t   s e t < N o d e I d > &   t a r g e t N o d e I d s ) 
 { 
         d y n a m i c A p p l i c a t i o n D a t a s . p u s h _ b a c k ( 
                 D y n a m i c A p p l u c a t i o n D a t a ( 
                         s o u r c e N o d e I d , 
                         i n s t a n c e I d , 
                         p a r a m e t e r L i n e s , 
                         t a r g e t N o d e I d s ) ) ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : S y n c A p p l i c a t i o n C r e a t i o n ( ) 
 { 
         f o r ( s i z e _ t   j   =   0 ;   j   <   d y n a m i c A p p l i c a t i o n D a t a s . s i z e ( ) ;   j + + )   { 
                 c o n s t   D y n a m i c A p p l u c a t i o n D a t a &   d y n a m i c A p p l i c a t i o n D a t a   =   d y n a m i c A p p l i c a t i o n D a t a s [ j ] ; 
 
                 ( * t h i s ) . G e n e r a t e D y n a m i c A p p l i c a t i o n ( d y n a m i c A p p l i c a t i o n D a t a ) ; 
         } 
 
         d y n a m i c A p p l i c a t i o n D a t a s . c l e a r ( ) ; 
 } 
 
 v o i d   M u l t i A g e n t S i m u l a t o r : : G e n e r a t e D y n a m i c A p p l i c a t i o n ( c o n s t   D y n a m i c A p p l u c a t i o n D a t a &   d y n a m i c A p p l i c a t i o n D a t a ) 
 { 
         c o n s t   N o d e I d &   s o u r c e N o d e I d   =   d y n a m i c A p p l i c a t i o n D a t a . s o u r c e N o d e I d ; 
         c o n s t   I n t e r f a c e O r I n s t a n c e I d &   i n s t a n c e I d   =   d y n a m i c A p p l i c a t i o n D a t a . i n s t a n c e I d ; 
         c o n s t   v e c t o r < s t r i n g > &   p a r a m e t e r L i n e s   =   d y n a m i c A p p l i c a t i o n D a t a . p a r a m e t e r L i n e s ; 
         c o n s t   s e t < N o d e I d > &   t a r g e t N o d e I d s   =   d y n a m i c A p p l i c a t i o n D a t a . t a r g e t N o d e I d s ; 
 
         a s s e r t ( ! p a r a m e t e r L i n e s . e m p t y ( ) ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   p a r a m e t e r L i n e s . s i z e ( ) ;   i + + )   { 
                 c o n s t   s t r i n g &   p a r a m e t e r L i n e   =   p a r a m e t e r L i n e s [ i ] ; 
 
                 b o o l   f o u n d A n E r r o r ; 
 
                 t h e P a r a m e t e r D a t a b a s e R e a d e r P t r - > A d d N e w D e f i n i t i o n T o D a t a b a s e ( p a r a m e t e r L i n e ,   f o u n d A n E r r o r ) ; 
 
                 i f   ( f o u n d A n E r r o r )   { 
                         c e r r   < <   " E r r o r :   F a i l e d   t o   a d d   d y n a m i c   a p p l i c a t i o n   l i n e   "   < <   p a r a m e t e r L i n e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
         } 
 
         u s i n g   s t d : : d y n a m i c _ p o i n t e r _ c a s t ; 
 
         i f   ( t a r g e t N o d e I d s . f i n d ( A N Y _ N O D E I D )   ! =   t a r g e t N o d e I d s . e n d ( ) )   { 
 
                 t y p e d e f   m a p < N o d e I d ,   s h a r e d _ p t r < N e t w o r k N o d e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
                 f o r ( I t e r T y p e   i t e r   =   n o d e s . b e g i n ( ) ;   i t e r   ! =   n o d e s . e n d ( ) ;   i t e r + + )   { 
 
                         s h a r e d _ p t r < N e t w o r k N o d e >   a N o d e P t r   =   ( * i t e r ) . s e c o n d ; 
 
                         i f   ( a N o d e P t r   ! =   n u l l p t r )   { 
                                   a N o d e P t r - > C r e a t e D y n a m i c A p p l i c a t i o n ( 
                                         * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                                         t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                                         s o u r c e N o d e I d , 
                                         i n s t a n c e I d ) ; 
                         } 
                 } 
 
         }   e l s e   { 
 
                 t y p e d e f   s e t < N o d e I d > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
                 f o r ( I t e r T y p e   i t e r   =   t a r g e t N o d e I d s . b e g i n ( ) ;   i t e r   ! =   t a r g e t N o d e I d s . e n d ( ) ;   i t e r + + )   { 
                         c o n s t   N o d e I d &   t h e N o d e I d   =   ( * i t e r ) ; 
 
                         i f   ( n o d e s . f i n d ( t h e N o d e I d )   = =   n o d e s . e n d ( ) )   { 
                                 c e r r   < <   " E r r o r :   N e t w o r k   N o d e   I d :   "   < <   t h e N o d e I d   < <   "   N o t   F o u n d . "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
 
                         c o n s t   s h a r e d _ p t r < N e t w o r k N o d e >   n e t w o r k N o d e P t r   =   n o d e s [ t h e N o d e I d ] ; 
 
                         i f   ( n e t w o r k N o d e P t r   = =   n u l l p t r )   { 
                                 c e r r   < <   " E r r o r :   N e t w o r k   N o d e   I d :   "   < <   t h e N o d e I d   < <   "   i s   n o t   N e t w o r k N o d e . "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
 
                         n e t w o r k N o d e P t r - > C r e a t e D y n a m i c A p p l i c a t i o n ( 
                                 * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                                 t h e G l o b a l N e t w o r k i n g O b j e c t B a g , 
                                 s o u r c e N o d e I d , 
                                 i n s t a n c e I d ) ; 
                 } 
         } 
 } 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 # p r a g m a   w a r n i n g ( d i s a b l e : 4 3 5 5 ) 
 
 A g e n t P r o f i l e A n d T a s k T a b l e : : A g e n t P r o f i l e A n d T a s k T a b l e ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   i n i t P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
         c o n s t   s h a r e d _ p t r < G i s S u b s y s t e m > &   i n i t G i s S u b s y s t e m P t r , 
         c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e ) 
         : 
         t h e P u b l i c V e h i c l e T a b l e P t r ( i n i t P u b l i c V e h i c l e T a b l e P t r ) , 
         e m p t y T a s k T a b l e P t r ( n e w   A g e n t T a s k T a b l e ( t h i s ) ) 
 { 
         c o n s t   s t r i n g   a g e n t P r o f i l e F i l e P a t h   = 
                 i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( 
                         " m u l t i a g e n t - p r o f i l e - f i l e " ) ; 
 
         c o n s t   S i m T i m e   s t a r t T i m e   = 
                 i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d T i m e ( 
                         " m u l t i a g e n t - s t a r t - t i m e " ) ; 
 
         c o n s t   d o u b l e   s t a r t T i m e S e c   =   s t a t i c _ c a s t < d o u b l e > ( s t a r t T i m e   /   S E C O N D ) ; 
 
         ( * t h i s ) . L o a d P r o f i l e ( 
                 * i n i t G i s S u b s y s t e m P t r ,   m a s t e r R e s o u r c e ,   a g e n t P r o f i l e F i l e P a t h ,   s t a r t T i m e S e c ) ; 
 } 
 
 # p r a g m a   w a r n i n g ( d e f a u l t : 4 3 5 5 ) 
 
 v o i d   A g e n t P r o f i l e A n d T a s k T a b l e : : C o m p l e t e I n i t i a l i z e ( 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   i n i t P a r a m e t e r D a t a b a s e R e a d e r , 
         c o n s t   s h a r e d _ p t r < G i s S u b s y s t e m > &   i n i t G i s S u b s y s t e m P t r , 
         c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
         c o n s t   s e t < A g e n t I d T y p e > &   e n t i r e A g e n t I d s ) 
 { 
         c o n s t   s t r i n g   a g e n t S c h e d u l e F i l e P a t h   = 
                 i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( 
                         " m u l t i a g e n t - b e h a v i o r - f i l e " ) ; 
 
         c o n s t   S i m T i m e   s t a r t T i m e   = 
                 i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d T i m e ( 
                         " m u l t i a g e n t - s t a r t - t i m e " ) ; 
 
         c o n s t   d o u b l e   s t a r t T i m e S e c   =   s t a t i c _ c a s t < d o u b l e > ( s t a r t T i m e   /   S E C O N D ) ; 
 
         m a p < s t r i n g ,   s e t < s t r i n g >   >   a v a i l a b l e T a s k T a b l e s ; 
 
         t y p e d e f   s e t < A g e n t I d T y p e > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         f o r ( I t e r T y p e   i t e r   =   e n t i r e A g e n t I d s . b e g i n ( ) ;   i t e r   ! =   e n t i r e A g e n t I d s . e n d ( ) ;   i t e r + + )   { 
 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d   =   ( * i t e r ) ; 
 
                 c o n s t   s t r i n g   p r o f i l e N a m e   =   M a k e L o w e r C a s e S t r i n g ( 
                         i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( 
                                 " m u l t i a g e n t - p r o f i l e - t y p e " ,   a g e n t I d ) ) ; 
 
                 c o n s t   s t r i n g   t a s k T a b l e N a m e   =   M a k e L o w e r C a s e S t r i n g ( 
                         i n i t P a r a m e t e r D a t a b a s e R e a d e r . R e a d S t r i n g ( 
                                 " m u l t i a g e n t - b e h a v i o r - t y p e " ,   a g e n t I d ) ) ; 
 
                 i f   ( A S t r i n g S t a r t s W i t h ( p r o f i l e N a m e ,   " t a x i " )   | | 
                         p r o f i l e N a m e   = =   " t r a i n "   | | 
                         p r o f i l e N a m e   = =   " b u s "   | | 
                         p r o f i l e N a m e   = =   " v e h i c l e "   | | 
                         p r o f i l e N a m e   = =   " p r i v a t e c a r " )   { 
                         / /   s k i p . 
                 }   e l s e   { 
                         a v a i l a b l e T a s k T a b l e s [ t a s k T a b l e N a m e ] . i n s e r t ( p r o f i l e N a m e ) ; 
                 } 
         } 
 
         ( * t h i s ) . L o a d T a s k T a b l e ( 
                 * i n i t G i s S u b s y s t e m P t r ,   m a s t e r R e s o u r c e ,   a g e n t S c h e d u l e F i l e P a t h ,   s t a r t T i m e S e c ,   a v a i l a b l e T a s k T a b l e s ) ; 
 } 
 
 s h a r e d _ p t r < A g e n t P r o f i l e >   A g e n t P r o f i l e A n d T a s k T a b l e : : G e t P r o f i l e ( c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t 
 { 
         i f   ( ! p r o f i l e P t r s . C o n t a i n s ( p r o f i l e N a m e ) )   { 
                 c e r r   < <   " E r r o r :   i n v a l i d   p r o f i l e   n a m e   "   < <   p r o f i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         r e t u r n   p r o f i l e P t r s [ p r o f i l e N a m e ] ; 
 } 
 
 s h a r e d _ p t r < A g e n t T a s k T a b l e >   A g e n t P r o f i l e A n d T a s k T a b l e : : G e t T a s k T a b l e ( 
                 c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
                 c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t 
 { 
         i f   ( ! p r o f i l e P t r s . C o n t a i n s ( p r o f i l e N a m e ) )   { 
                 c e r r   < <   " E r r o r :   i n v a l i d   p r o f i l e   n a m e   "   < <   p r o f i l e N a m e   < <   "   f o r   t a s k   "   < <   t a s k T a b l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         c o n s t   A g e n t P r o f i l e T y p e   p r o f i l e T y p e   =   p r o f i l e P t r s . G e t I d ( p r o f i l e N a m e ) ; 
 
         t y p e d e f   m a p < p a i r < s t r i n g ,   A g e n t P r o f i l e T y p e > ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   t a s k T a b l e P t r s . f i n d ( m a k e _ p a i r ( t a s k T a b l e N a m e ,   p r o f i l e T y p e ) ) ; 
 
         i f   ( i t e r   = =   t a s k T a b l e P t r s . e n d ( ) )   { 
                 c e r r   < <   " S p e c i f y   a v a i l a b l e   B e h a v i o r   f o r   A g e n t : "   < <   t a s k T a b l e N a m e   < <     "   P r o f i l e : "   < <   p r o f i l e N a m e   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         r e t u r n   ( * i t e r ) . s e c o n d ; 
 } 
 
 b o o l   A g e n t P r o f i l e A n d T a s k T a b l e : : C o n t a i n s T a s k ( 
         c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
         c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t 
 { 
         i f   ( ! p r o f i l e P t r s . C o n t a i n s ( p r o f i l e N a m e ) )   { 
                 r e t u r n   f a l s e ; 
         } 
 
         c o n s t   A g e n t P r o f i l e T y p e   p r o f i l e T y p e   =   p r o f i l e P t r s . G e t I d ( p r o f i l e N a m e ) ; 
 
         t y p e d e f   m a p < p a i r < s t r i n g ,   A g e n t P r o f i l e T y p e > ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
         I t e r T y p e   i t e r   =   t a s k T a b l e P t r s . f i n d ( m a k e _ p a i r ( t a s k T a b l e N a m e ,   p r o f i l e T y p e ) ) ; 
 
         r e t u r n   ( i t e r   ! =   t a s k T a b l e P t r s . e n d ( ) ) ; 
 } 
 
 v e c t o r < s t r i n g >   A g e n t P r o f i l e A n d T a s k T a b l e : : G e t P r o f i l e T y p e N a m e s ( )   c o n s t 
 { 
         v e c t o r < s t r i n g >   p r o f i l e T y p e N a m e s ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   p r o f i l e P t r s . S i z e ( ) ;   i + + )   { 
                 p r o f i l e T y p e N a m e s . p u s h _ b a c k ( p r o f i l e P t r s [ A g e n t P r o f i l e T y p e ( i ) ] - > G e t P r o f i l e N a m e ( ) ) ; 
         } 
 
         r e t u r n   p r o f i l e T y p e N a m e s ; 
 } 
 
 v o i d   A g e n t P r o f i l e A n d T a s k T a b l e : : L o a d P r o f i l e ( 
         c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
         c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
         c o n s t   s t r i n g &   p r o f i l e F i l e P a t h , 
         c o n s t   d o u b l e   s t a r t T i m e S e c ) 
 { 
         i f s t r e a m   i n S t r e a m ( p r o f i l e F i l e P a t h . c _ s t r ( ) ) ; 
 
         i f   ( ! i n S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   P r o f i l e   f i l e   "   < <   p r o f i l e F i l e P a t h   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         A g e n t P r o f i l e T y p e   p r o f i l e T y p e   =   I N V A L I D _ A G E N T _ T Y P E ; 
         s e t < s t r i n g >   s p e c i f i e d p a r a m e t e r N a m e s ; 
 
         w h i l e ( ! i n S t r e a m . e o f ( ) )   { 
                 s t r i n g   a L i n e ; 
                 g e t l i n e ( i n S t r e a m ,   a L i n e ) ; 
 
                 D e l e t e T r a i l i n g S p a c e s ( a L i n e ) ; 
 
                 i f   ( I s A C o n f i g F i l e C o m m e n t L i n e ( a L i n e ) )   { 
                         c o n t i n u e ; 
                 } 
 
                 i f   ( A S t r i n g S t a r t s W i t h ( M a k e L o w e r C a s e S t r i n g ( a L i n e ) ,   " p r o f i l e t y p e " ) )   { 
                         c o n s t   s t r i n g   p r o f i l e N a m e   =   S e p a r a t e S t r i n g ( a L i n e ,     " : " ) . s e c o n d ; 
 
                         i f   ( p r o f i l e N a m e . e m p t y ( ) )   { 
                                 c e r r   < <   " E r r o r   c a n ' t   r e a d   a g e n t   l i n e   "   < <   a L i n e   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
 
                         p r o f i l e T y p e   =   p r o f i l e P t r s . G e t I d ( M a k e L o w e r C a s e S t r i n g ( p r o f i l e N a m e ) ) ; 
 
                         p r o f i l e P t r s [ p r o f i l e T y p e ] . r e s e t ( n e w   A g e n t P r o f i l e ( p r o f i l e T y p e ,   p r o f i l e N a m e ) ) ; 
                         s p e c i f i e d p a r a m e t e r N a m e s . c l e a r ( ) ; 
                         c o n t i n u e ; 
                 } 
 
                 C o n v e r t S t r i n g T o L o w e r C a s e ( a L i n e ) ; 
 
                 i f   ( p r o f i l e T y p e   = =   I N V A L I D _ A G E N T _ T Y P E )   { 
                         c e r r   < <   " E r r o r : D e f i n e   P r o f i l e   i n   A g e n r P r o f i l e   f i l e . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 d e q u e < s t r i n g >   p a r a m e t e r N a m e A n d V a l u e ; 
                 T o k e n i z e T o T r i m m e d L o w e r S t r i n g ( a L i n e ,   " = " ,   p a r a m e t e r N a m e A n d V a l u e ) ; 
 
                 i f   ( p a r a m e t e r N a m e A n d V a l u e . s i z e ( )   ! =   2 )   { 
                         c e r r   < <   " E r r o r : P a r e m t e r   d e f i n i t i o n   f o r   "   < <   p r o f i l e P t r s . G e t L a b e l ( p r o f i l e T y p e )   < <   "   : "   < <   a L i n e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 c o n s t   s t r i n g &   p a r a m e t e r N a m e   =   p a r a m e t e r N a m e A n d V a l u e [ 0 ] ; 
                 c o n s t   s t r i n g &   v a l u e   =   p a r a m e t e r N a m e A n d V a l u e [ 1 ] ; 
 
                 i f   ( s p e c i f i e d p a r a m e t e r N a m e s . f i n d ( p a r a m e t e r N a m e )   ! =   s p e c i f i e d p a r a m e t e r N a m e s . e n d ( ) )   { 
                         c e r r   < <   " E r r o r :   P r o f i l e   \ " "   < <   p a r a m e t e r N a m e   < <   " \ "   i s   d u p l i c a t e d   i n   \ " "   < <     p r o f i l e P t r s . G e t L a b e l ( p r o f i l e T y p e )   < <   " \ " "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } / / i f / / 
 
                 s p e c i f i e d p a r a m e t e r N a m e s . i n s e r t ( p a r a m e t e r N a m e ) ; 
 
                 i f   ( p a r a m e t e r N a m e   = =   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ P R I V A T E _ C A R _ O W N E R S H I P ] )   { 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         p r o f i l e . h a s C a r   = 
                                 A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                 }   e l s e   i f   ( p a r a m e t e r N a m e   = =   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ B I C Y C L E _ O W N E R S H I P ] )   { 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         p r o f i l e . h a s B i c y c l e   = 
                                 A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                 }   e l s e   i f   ( p a r a m e t e r N a m e   = =   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ W A L K _ S P E E D _ A T _ T R A N S F E R ] )   { 
 
                         c o n s t   s t r i n g &   m o b i l i t y T y p e   =   v a l u e ; 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         p r o f i l e . m o b i l i t y C l a s s   =   G e t A g e n t M o b i l i t y C l a s s ( m o b i l i t y T y p e ) ; 
 
                 }   e l s e   i f   ( p a r a m e t e r N a m e   = =   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ U T I L I T Y 1 _ F U N C T I O N ]   | |   p a r a m e t e r N a m e   = =   " u t i l i t y f u n c t i o n " / * o b s o l e t e * / )   { 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         p r o f i l e . u t i l i t y F o r m u l a 1   = 
                                 A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                 }   e l s e   i f   ( p a r a m e t e r N a m e   = =   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ U T I L I T Y 2 _ F U N C T I O N ] )   { 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         p r o f i l e . u t i l i t y F o r m u l a 2   = 
                                 A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                 }   e l s e   i f   ( p a r a m e t e r N a m e   = =   R E S E R V E D _ S P E C I A L _ A G E N T _ S T A T U S _ N A M E S [ A G E N T _ R E S E R V E D _ S P E C I A L _ S T A T U S _ R O U T E _ P R I O R I T Y ] )   { 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         c o n s t   A g e n t V a l u e F o r m u l a   a F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         i f   ( p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - p e d e s t r i a n "   | | 
                                 p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - w a l k " )   { 
 
                                 p r o f i l e . r o u t e C o s t F o r m u l a s [ A G E N T _ B E H A V I O R _ P E D E S T R I A N ]   =   a F o r m u l a ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - b i c y c l e " )   { 
 
                                 p r o f i l e . r o u t e C o s t F o r m u l a s [ A G E N T _ B E H A V I O R _ B I C Y C L E ]   =   a F o r m u l a ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - p r i v a t e c a r " )   { 
 
                                 p r o f i l e . r o u t e C o s t F o r m u l a s [   A G E N T _ B E H A V I O R _ V E H I C L E ]   =   a F o r m u l a ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - t r a i n " )   { 
 
                                 p r o f i l e . r o u t e C o s t F o r m u l a s [ A G E N T _ B E H A V I O R _ T R A I N ]   =   a F o r m u l a ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - b u s " )   { 
 
                                 p r o f i l e . r o u t e C o s t F o r m u l a s [ A G E N T _ B E H A V I O R _ B U S ]   =   a F o r m u l a ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " r o u t e p r i o r i t y - t a x i " )   { 
 
                                 p r o f i l e . r o u t e C o s t F o r m u l a s [ A G E N T _ B E H A V I O R _ T A X I ]   =   a F o r m u l a ; 
 
                         }   e l s e   { 
 
                                 f o r ( s i z e _ t   i   =   0 ;   i   <   p r o f i l e . r o u t e C o s t F o r m u l a s . s i z e ( ) ;   i + + )   { 
                                         i f   ( p r o f i l e . r o u t e C o s t F o r m u l a s [ i ] . I s N u l l ( ) )   { 
                                                 p r o f i l e . r o u t e C o s t F o r m u l a s [ i ]   =   a F o r m u l a ; 
                                         } 
                                 } 
                         } 
 
                 }   e l s e   { 
                         A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
                         d o u b l e   d e f a u l t V a l u e   =   0 ; 
 
                         c o n s t   A g e n t S t a t u s I d T y p e   s t a t u s I d   =   p r o f i l e . p a r a m e t e r s . G e t I d ( p a r a m e t e r N a m e ) ; 
 
                         i f   ( A G E N T _ R E S E R V E D _ S T A T U S _ Q U E R Y _ T R I G G E R _ S T A R T   < =   s t a t u s I d   & & 
                                 s t a t u s I d   < =   A G E N T _ R E S E R V E D _ S T A T U S _ Q U E R Y _ T R I G G E R _ E N D   )   { 
                                 d e f a u l t V a l u e   =   D B L _ M A X ; 
                         } 
 
                         p r o f i l e . p a r a m e t e r s [ p a r a m e t e r N a m e ]   = 
                                 A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ,   d e f a u l t V a l u e ) ; 
                 } 
         } 
 } 
 
 s t a t i c   i n l i n e 
 b o o l   I s E q u a l S t r i n g ( c o n s t   s t r i n g &   a S t r i n g ) 
 { 
         c o n s t   s i z e _ t   e q u a l P o s   =   a S t r i n g . f i n d ( " = " ) ; 
 
         i f   ( e q u a l P o s   ! =   s t r i n g : : n p o s )   { 
 
                 c o n s t   s i z e _ t   c o n d i t i o n P o s   =   a S t r i n g . f i n d _ f i r s t _ o f ( " = < > ! " ,   e q u a l P o s   +   1 ) ; 
 
                 i f   ( c o n d i t i o n P o s   = =   e q u a l P o s   +   1 )   { 
                         r e t u r n   f a l s e ; 
                 } 
 
                 r e t u r n   t r u e ; 
         } 
 
         r e t u r n   f a l s e ; 
 } 
 
 v o i d   A g e n t P r o f i l e A n d T a s k T a b l e : : L o a d T a s k T a b l e ( 
         c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
         c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
         c o n s t   s t r i n g &   b e h a v i o r F i l e P a t h , 
         c o n s t   d o u b l e   s t a r t T i m e S e c , 
         c o n s t   m a p < s t r i n g ,   s e t < s t r i n g >   > &   a v a i l a b l e T a s k T a b l e s ) 
 { 
         i f s t r e a m   i n S t r e a m ( b e h a v i o r F i l e P a t h . c _ s t r ( ) ) ; 
 
         i f   ( ! i n S t r e a m . g o o d ( ) )   { 
                 c e r r   < <   " E r r o r :   C o u l d n ' t   o p e n   B e h a v i o r   f i l e   "   < <   b e h a v i o r F i l e P a t h   < <   e n d l ; 
                 e x i t ( 1 ) ; 
         } 
 
         / / A g e n t T a s k T a b l e T y p e   t a s k T a b l e T y p e   =   I N V A L I D _ T A S K _ T A B L E _ T Y P E ; 
         s t r i n g   t a s k T a b l e N a m e ; 
         v e c t o r < s t r i n g >   p r o f i l e N a m e s ; 
         v e c t o r < p a i r < A g e n t P r o f i l e T y p e ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   >   >   d e f a u l t P r o f i l e T a s k T a b l e P t r s ; 
 
         w h i l e ( ! i n S t r e a m . e o f ( ) )   { 
                 s t r i n g   a L i n e ; 
                 g e t l i n e ( i n S t r e a m ,   a L i n e ) ; 
 
                 D e l e t e T r a i l i n g S p a c e s ( a L i n e ) ; 
 
                 i f   ( I s A C o n f i g F i l e C o m m e n t L i n e ( a L i n e ) )   { 
                         c o n t i n u e ; 
                 } 
                 C o n v e r t S t r i n g T o L o w e r C a s e ( a L i n e ) ; 
 
                 i f   ( A S t r i n g S t a r t s W i t h ( a L i n e ,   " l o c a t i o n g r o u p " ) )   { 
 
                         c o n s t   p a i r < s t r i n g ,   s t r i n g > &   g r o u p N a m e A n d l o c a t i o n N a m e s   = 
                                 S e p a r a t e S t r i n g ( a L i n e . s u b s t r ( s t r i n g ( " l o c a t i o n g r o u p " ) . l e n g t h ( ) ) ,     " = " ) ; 
 
                         d e q u e < s t r i n g >   l o c a t i o n N a m e s ; 
                         T o k e n i z e T o T r i m m e d L o w e r S t r i n g ( g r o u p N a m e A n d l o c a t i o n N a m e s . s e c o n d ,   " , " ,   l o c a t i o n N a m e s ) ; 
 
                         v e c t o r < G i s P o s i t i o n I d T y p e > &   p o s i t i o n I d s   = 
                                 l o c a t i o n G r o u p s [ g r o u p N a m e A n d l o c a t i o n N a m e s . f i r s t ] ; 
 
                         f o r ( s i z e _ t   i   =   0 ;   i   <   l o c a t i o n N a m e s . s i z e ( ) ;   i + + )   { 
                                 c o n s t   G i s P o s i t i o n I d T y p e   p o s i t i o n I d   =   t h e G i s S u b s y s t e m . G e t P o s i t i o n ( l o c a t i o n N a m e s [ i ] ) ; 
 
                                 i f   ( p o s i t i o n I d . t y p e   = =   G I S _ B U I L D I N G   | | 
                                         p o s i t i o n I d . t y p e   = =   G I S _ P A R K   | | 
                                         p o s i t i o n I d . t y p e   = =   G I S _ P O I   | | 
                                         p o s i t i o n I d . t y p e   = =   G I S _ A R E A )   { 
                                         p o s i t i o n I d s . p u s h _ b a c k ( p o s i t i o n I d ) ; 
                                 } 
                                 e l s e   { 
                                         c e r r   < <   " E r r o r :   G r o u p   l o c a t i o n   c a n   c o n t a i n   b u i l d i n g ,   p a r k ,   P O I   o r   a r e a   n a m e s   o n l y .   n a m e : "   < <   t h e G i s S u b s y s t e m . G e t G i s O b j e c t ( p o s i t i o n I d ) . G e t O b j e c t N a m e ( )   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
                         } 
 
                 }   e l s e   i f   ( A S t r i n g S t a r t s W i t h ( a L i n e ,   " l o c a t i o n i d g r o u p " ) )   { 
 
                         c o n s t   p a i r < s t r i n g ,   s t r i n g > &   g r o u p N a m e A n d l o c a t i o n N a m e s   = 
                                 S e p a r a t e S t r i n g ( a L i n e . s u b s t r ( s t r i n g ( " l o c a t i o n i d g r o u p " ) . l e n g t h ( ) ) ,     " = " ) ; 
 
                         d e q u e < s t r i n g >   l o c a t i o n N a m e s ; 
                         T o k e n i z e T o T r i m m e d L o w e r S t r i n g ( g r o u p N a m e A n d l o c a t i o n N a m e s . s e c o n d ,   " , " ,   l o c a t i o n N a m e s ) ; 
 
                         v e c t o r < G i s P o s i t i o n I d T y p e > &   p o s i t i o n I d s   = 
                                 l o c a t i o n G r o u p s [ g r o u p N a m e A n d l o c a t i o n N a m e s . f i r s t ] ; 
 
                         f o r ( s i z e _ t   i   =   0 ;   i   <   l o c a t i o n N a m e s . s i z e ( ) ;   i + + )   { 
                                 b o o l   s u c c e s s ; 
                                 i n t   a V a l u e ; 
                                 C o n v e r t S t r i n g T o I n t ( l o c a t i o n N a m e s [ i ] ,   a V a l u e ,   s u c c e s s ) ; 
 
                                 i f   ( ! s u c c e s s )   { 
                                         c e r r   < <   " W r o n g   f o r m a t   s t r i n g   f o r   i n t   v a l u e "   < <   l o c a t i o n N a m e s [ i ]   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 p o s i t i o n I d s . p u s h _ b a c k ( 
                                         t h e G i s S u b s y s t e m . G e t P o s i t i o n I d ( G i s O b j e c t I d T y p e ( a V a l u e ) ) ) ; 
                         } 
 
                 }   e l s e   i f   ( A S t r i n g S t a r t s W i t h ( a L i n e ,   " b e h a v i o r t y p e " ) )   { 
                         c o n s t   s t r i n g   b e h a v i o r N a m e   =   S e p a r a t e S t r i n g ( a L i n e ,     " : " ) . s e c o n d ; 
 
                         i f   ( b e h a v i o r N a m e . e m p t y ( ) )   { 
                                 c e r r   < <   " E r r o r   c a n ' t   r e a d   a g e n t   l i n e   "   < <   a L i n e   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
 
                         t y p e d e f   m a p < s t r i n g ,   s e t < s t r i n g >   > : : c o n s t _ i t e r a t o r   T a s k T a b l e I t e r ; 
 
                         T a s k T a b l e I t e r   t a s k T a b l e I t e r   =   a v a i l a b l e T a s k T a b l e s . f i n d ( b e h a v i o r N a m e ) ; 
 
                         i f   ( t a s k T a b l e I t e r   ! =   a v a i l a b l e T a s k T a b l e s . e n d ( ) )   { 
                                 t a s k T a b l e N a m e   =   b e h a v i o r N a m e ; 
 
                                 t y p e d e f   s e t < s t r i n g > : : c o n s t _ i t e r a t o r   P r o f i l e N a m e I t e r ; 
 
                                 c o n s t   s e t < s t r i n g > &   a v a i l a b l e P r o f i l e N a m e s   =   ( * t a s k T a b l e I t e r ) . s e c o n d ; 
 
                                 d e f a u l t P r o f i l e T a s k T a b l e P t r s . c l e a r ( ) ; 
 
                                 f o r ( P r o f i l e N a m e I t e r   n a m e I t e r   =   a v a i l a b l e P r o f i l e N a m e s . b e g i n ( ) ; 
                                         n a m e I t e r   ! =   a v a i l a b l e P r o f i l e N a m e s . e n d ( ) ;   n a m e I t e r + + )   { 
 
                                         c o n s t   s t r i n g &   p r o f i l e N a m e   =   ( * n a m e I t e r ) ; 
 
                                         i f   ( ( ! p r o f i l e P t r s . C o n t a i n s ( p r o f i l e N a m e ) )   & & 
                                                 ( p r o f i l e N a m e   ! =   " { s i m u l a t i o n _ n o d e _ i d } " ) )   { 
                                                 c e r r   < <   " E r r o r :   i n v a l i d   p r o f i l e   n a m e   "   < <   p r o f i l e N a m e   < <   e n d l ; 
                                                 e x i t ( 1 ) ; 
                                         } 
 
                                         c o n s t   A g e n t P r o f i l e T y p e   p r o f i l e T y p e   =   p r o f i l e P t r s . G e t I d ( p r o f i l e N a m e ) ; 
 
                                         d e f a u l t P r o f i l e T a s k T a b l e P t r s . p u s h _ b a c k ( 
                                                 m a k e _ p a i r ( p r o f i l e T y p e , 
                                                                     s h a r e d _ p t r < A g e n t T a s k T a b l e > ( n e w   A g e n t T a s k T a b l e ( t h i s ) ) ) ) ; 
 
                                         t a s k T a b l e P t r s [ m a k e _ p a i r ( b e h a v i o r N a m e ,   p r o f i l e T y p e ) ]   = 
                                                 d e f a u l t P r o f i l e T a s k T a b l e P t r s . b a c k ( ) . s e c o n d ; 
                                 } 
 
                         }   e l s e   { 
                                 t a s k T a b l e N a m e . c l e a r ( ) ; 
                         } 
 
                 }   e l s e   i f   ( ! t a s k T a b l e N a m e . e m p t y ( ) )   { 
 
                         ( * t h i s ) . A d d T a s k ( 
                                 t h e G i s S u b s y s t e m , 
                                 t a s k T a b l e N a m e , 
                                 m a s t e r R e s o u r c e , 
                                 a L i n e , 
                                 s t a r t T i m e S e c , 
                                 d e f a u l t P r o f i l e T a s k T a b l e P t r s , 
                                 l o c a t i o n G r o u p s ) ; 
                 } 
         } 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   S e p a r a t e T o C o n d i t i o n A n d A c t i o n S t r i n g ( 
         c o n s t   s t r i n g &   t a s k L i n e , 
         s t r i n g &   c o n d i t i o n S t r i n g , 
         s t r i n g &   a c t i o n S t r i n g ) 
 { 
         s i z e _ t   n u m b e r R e m a i n i n g A r c s   =   0 ; 
         s i z e _ t   c u r r e n t P o s   =   0 ; 
         s i z e _ t   c o n d i t i o n S t a r t P o s   =   1 ; 
         s i z e _ t   c o n d i t i o n E n d P o s   =   0 ; 
 
         d o   { 
                 c u r r e n t P o s   =   t a s k L i n e . f i n d _ f i r s t _ o f ( " [ ] " ,   c u r r e n t P o s ) ; 
 
                 i f   ( c u r r e n t P o s   ! =   s t r i n g : : n p o s )   { 
                         i f   ( t a s k L i n e [ c u r r e n t P o s ]   = =   ' [ ' )   { 
                                 i f   ( n u m b e r R e m a i n i n g A r c s   = =   0 )   { 
                                         c o n d i t i o n S t a r t P o s   =   c u r r e n t P o s   +   1 ; 
                                 } 
                                 n u m b e r R e m a i n i n g A r c s + + ; 
                         }   e l s e   { 
                                 i f   ( n u m b e r R e m a i n i n g A r c s   = =   0 )   { 
                                         c e r r   < <   " E r r o r :   l a c k   o f   \ " [ \ " : "   < <   t a s k L i n e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
                                 i f   ( n u m b e r R e m a i n i n g A r c s   = =   1 )   { 
                                         c o n d i t i o n E n d P o s   =   c u r r e n t P o s   -   1 ; 
                                 } 
                                 n u m b e r R e m a i n i n g A r c s - - ; 
                         } 
                         c u r r e n t P o s + + ; 
                 } 
 
         }   w h i l e   ( n u m b e r R e m a i n i n g A r c s   ! =   0   & &   c u r r e n t P o s   ! =   s t r i n g : : n p o s ) ; 
 
         i f   ( c o n d i t i o n E n d P o s   > =   c o n d i t i o n S t a r t P o s )   { 
                 c o n d i t i o n S t r i n g   =   t a s k L i n e . s u b s t r ( c o n d i t i o n S t a r t P o s ,   c o n d i t i o n E n d P o s   -   c o n d i t i o n S t a r t P o s   +   1 ) ; 
                 a c t i o n S t r i n g   =   t a s k L i n e . s u b s t r ( c o n d i t i o n E n d P o s   +   2 ) ; 
         }   e l s e   { 
                 c o n d i t i o n S t r i n g   =   " " ; 
                 a c t i o n S t r i n g   =   t a s k L i n e ; 
         } 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   R e s o l v e A p p l i c a t i o n P a r a m e t e r S p e c i f i c a t i o n ( 
         c o n s t   s t r i n g &   p a r a m e t e L i n e , 
         s t r i n g &   i n s t a n c e N a m e , 
         s t r i n g &   m o d e l N a m e , 
         v e c t o r < D y n a m i c A p p l i c a t i o n D e f i n i t i o n P a r a m e t e r > &   p a r a m e t e r s ) 
 { 
         p a r a m e t e r s . c l e a r ( ) ; 
 
         s t r i n g   a p p l i c a t i o n S p e c i f i c a i t o n L i n e ; 
 
         S e p a r a t e T o C o n d i t i o n A n d A c t i o n S t r i n g ( p a r a m e t e L i n e ,   i n s t a n c e N a m e ,   a p p l i c a t i o n S p e c i f i c a i t o n L i n e ) ; 
 
         d e q u e < s t r i n g >   p a r a m e t e r T o k e n s ; 
         T o k e n i z e T o T r i m m e d L o w e r S t r i n g W i t h A r c ( a p p l i c a t i o n S p e c i f i c a i t o n L i n e ,   " , " ,   p a r a m e t e r T o k e n s ) ; 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   p a r a m e t e r T o k e n s . s i z e ( ) ;   i + + )   { 
                 c o n s t   p a i r < s t r i n g ,   s t r i n g > &   p a r a m e t e r A n d V a l u e   = 
                         S e p a r a t e S t r i n g ( p a r a m e t e r T o k e n s [ i ] ,     " = " ) ; 
 
                 p a r a m e t e r s . p u s h _ b a c k ( 
                         D y n a m i c A p p l i c a t i o n D e f i n i t i o n P a r a m e t e r ( 
                                 p a r a m e t e r A n d V a l u e . f i r s t , 
                                 p a r a m e t e r A n d V a l u e . s e c o n d ) ) ; 
         } 
 
         i f   ( ! p a r a m e t e r s . e m p t y ( ) )   { 
                 c o n s t   p a i r < s t r i n g ,   s t r i n g > &   p a r a m e t e r A n d V a l u e   = 
                         S e p a r a t e S t r i n g ( p a r a m e t e r s . f r o n t ( ) . a p p l i c a t i o n P a r a m e t e r N a m e ,     " - " ) ; 
 
                 m o d e l N a m e   =   p a r a m e t e r A n d V a l u e . f i r s t ; 
         }   e l s e   { 
                 m o d e l N a m e   =   " " ; 
         } 
 } 
 
 s t a t i c   i n l i n e 
 v o i d   P a r s e A c t i o n L i n e ( c o n s t   s t r i n g &   a c t i o n L i n e ,   d e q u e < s t r i n g > &   a c t i o n S t r i n g s ) 
 { 
         a c t i o n S t r i n g s . c l e a r ( ) ; 
 
         s i z e _ t   e q u a l P o s   =   0 ; 
         s i z e _ t   d e l i m P o s   =   0 ; 
 
         / /   Q u o t e   i s   r e p l a c e   b y   w h i t e   s p a c e   a c c o r d i n g   t o   p a r s i n g . 
         s t r i n g   s i m p l i f i e d A c t i o n L i n e     =   a c t i o n L i n e ; 
 
         w h i l e   ( t r u e )   { 
                 c o n s t   s i z e _ t   a c t i o n S t r i n g S t a r t P o s   =   d e l i m P o s ; 
 
                 e q u a l P o s   =   s i m p l i f i e d A c t i o n L i n e . f i n d _ f i r s t _ o f ( ' = ' ,   d e l i m P o s ) ; 
 
                 i f   ( e q u a l P o s   = =   s t r i n g : : n p o s )   { 
                         b r e a k ; 
                 } 
 
                 b o o l   v a l u e I s O u t O f Q u o t e   =   t r u e ; 
                 i n t   n u m b e r R e m a i n i n g A r c s   =   0 ; 
 
                 d e l i m P o s   =   e q u a l P o s   +   1 ; 
 
                 w h i l e   ( t r u e )   { 
 
                         d e l i m P o s   =   s i m p l i f i e d A c t i o n L i n e . f i n d _ f i r s t _ o f ( " , \ " ( ) " ,   d e l i m P o s ) ; 
 
                         i f   ( d e l i m P o s   = =   s t r i n g : : n p o s )   { 
                                 b r e a k ; 
                         } 
 
                         i f   ( s i m p l i f i e d A c t i o n L i n e [ d e l i m P o s ]   = =   ' ( ' )   { 
                                 n u m b e r R e m a i n i n g A r c s + + ; 
                                 d e l i m P o s + + ; 
                                 c o n t i n u e ; 
                         } 
 
                         i f   ( s i m p l i f i e d A c t i o n L i n e [ d e l i m P o s ]   = =   ' ) ' )   { 
                                 n u m b e r R e m a i n i n g A r c s - - ; 
                                 d e l i m P o s + + ; 
                                 c o n t i n u e ; 
                         } 
 
                         i f   ( v a l u e I s O u t O f Q u o t e   & & 
                                 n u m b e r R e m a i n i n g A r c s   = =   0   & & 
                                 s i m p l i f i e d A c t i o n L i n e [ d e l i m P o s ]   = =   ' , ' )   { 
 
                                 a c t i o n S t r i n g s . p u s h _ b a c k ( 
                                         s i m p l i f i e d A c t i o n L i n e . s u b s t r ( 
                                                 a c t i o n S t r i n g S t a r t P o s , 
                                                 d e l i m P o s   -   a c t i o n S t r i n g S t a r t P o s ) ) ; 
 
                                 d e l i m P o s + + ; 
                                 b r e a k ; 
                         } 
 
                         i f   ( s i m p l i f i e d A c t i o n L i n e [ d e l i m P o s ]   = =   ' " ' )   { 
                                 v a l u e I s O u t O f Q u o t e   =   ! v a l u e I s O u t O f Q u o t e ; 
                                 s i m p l i f i e d A c t i o n L i n e [ d e l i m P o s ]   =   '   ' ;   / / r e p l a c e 
                         } 
 
                         d e l i m P o s + + ; 
                 } 
 
                 i f   ( n u m b e r R e m a i n i n g A r c s   ! =   0 )   { 
                         c e r r   < <   " E r r o r :   M i s m a t c h e d   n u m b e r   o f   f u n c t i o n   a r c s   i n   "   < <   a c t i o n L i n e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 i f   ( d e l i m P o s   = =   s t r i n g : : n p o s )   { 
 
                         i f   ( ! v a l u e I s O u t O f Q u o t e )   { 
                                 c e r r   < <   " E r r o r :   i n v a l i d   b e h a v i o r   l i n e :   [ "   < <   a c t i o n L i n e   < <   " ]   C h e c k   n u m b e r   o f   \ " "   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
 
                         / /   f o u n d   a   s p e c i f i c a t i o n ( ; e q u a l )   b u t   n o   s e p a r a t o r   - - >   p u s h   l a s t   a c t i o n 
                         a c t i o n S t r i n g s . p u s h _ b a c k ( 
                                 s i m p l i f i e d A c t i o n L i n e . s u b s t r ( a c t i o n S t r i n g S t a r t P o s ) ) ; 
 
                         b r e a k ; 
                 } 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a c t i o n S t r i n g s . s i z e ( ) ;   i + + )   { 
                 C o n v e r t S t r i n g T o L o w e r C a s e ( a c t i o n S t r i n g s [ i ] ) ; 
         } 
 } 
 
 v o i d   A g e n t P r o f i l e A n d T a s k T a b l e : : A d d T a s k ( 
         c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
         c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
         c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
         c o n s t   s t r i n g &   t a s k L i n e , 
         c o n s t   d o u b l e   s t a r t T i m e S e c , 
         c o n s t   v e c t o r < p a i r < A g e n t P r o f i l e T y p e ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   >   > &   d e f a u l t P r o f i l e T a s k T a b l e P t r s , 
         c o n s t   m a p < s t r i n g ,   v e c t o r < G i s P o s i t i o n I d T y p e >   > &   l o c a t i o n G r o u p s _ N o t U s e d ) 
 { 
         s t r i n g   c o n d i t i o n L i n e ; 
         s t r i n g   a c t i o n L i n e ; 
 
         S e p a r a t e T o C o n d i t i o n A n d A c t i o n S t r i n g ( t a s k L i n e ,   c o n d i t i o n L i n e ,   a c t i o n L i n e ) ; 
 
         d e q u e < s t r i n g >   c o n d i t i o n S t r i n g s ; 
         T o k e n i z e T o T r i m m e d L o w e r S t r i n g W i t h A r c ( c o n d i t i o n L i n e ,   " , " ,   c o n d i t i o n S t r i n g s ) ; 
 
         d e q u e < s t r i n g >   a c t i o n S t r i n g s ; 
         P a r s e A c t i o n L i n e ( a c t i o n L i n e ,   a c t i o n S t r i n g s ) ; 
 
         v e c t o r < p a i r < A g e n t P r o f i l e T y p e ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   >   >   a v a i l a b l e P r o f i l e T a s k T a b l e P t r s ; 
         b o o l   f o u n d P r o f i l e T y p e S p e c i f i c a t i o n   =   f a l s e ; 
 
         f o r ( s i z e _ t   i   =   0 ;   ( ! f o u n d P r o f i l e T y p e S p e c i f i c a t i o n   & &   i   <   c o n d i t i o n S t r i n g s . s i z e ( ) ) ;   i + + )   { 
 
                 c o n s t   s t r i n g &   c o n d i t i o n S t r i n g   =   c o n d i t i o n S t r i n g s [ i ] ; 
 
                 i f   ( I s E q u a l S t r i n g ( c o n d i t i o n S t r i n g ) )   { 
                         c o n s t   p a i r < s t r i n g ,   s t r i n g > &   p a r a m e t e r A n d V a l u e   = 
                                 S e p a r a t e S t r i n g ( c o n d i t i o n S t r i n g ,     " = " ) ; 
 
                         i f   ( p a r a m e t e r A n d V a l u e . f i r s t   = =   " p r o f i l e t y p e " )   { 
                                 f o u n d P r o f i l e T y p e S p e c i f i c a t i o n   =   t r u e ; 
 
                                 d e q u e < s t r i n g >   p r o f i l e N a m e s ; 
                                 T o k e n i z e T o T r i m m e d L o w e r S t r i n g W i t h A r c ( p a r a m e t e r A n d V a l u e . s e c o n d ,   " ; " ,   p r o f i l e N a m e s ) ; 
 
                                 f o r ( s i z e _ t   j   =   0 ;   j   <   p r o f i l e N a m e s . s i z e ( ) ;   j + + )   { 
 
                                         c o n s t   s t r i n g &   p r o f i l e N a m e   =   p r o f i l e N a m e s [ j ] ; 
 
                                         i f   ( ! p r o f i l e P t r s . C o n t a i n s ( p r o f i l e N a m e ) )   { 
                                                 c e r r   < <   " E r r o r :   i n v a l i d   p r o f i l e   n a m e   "   < <   p r o f i l e N a m e   < <   "   a t   "   < <   c o n d i t i o n L i n e   < <   e n d l ; 
                                                 e x i t ( 1 ) ; 
                                         } 
 
                                         c o n s t   A g e n t P r o f i l e T y p e   p r o f i l e T y p e   =   p r o f i l e P t r s . G e t I d ( p r o f i l e N a m e ) ; 
 
                                         a v a i l a b l e P r o f i l e T a s k T a b l e P t r s . p u s h _ b a c k ( 
                                                 m a k e _ p a i r ( p r o f i l e T y p e , 
                                                                     t a s k T a b l e P t r s [ m a k e _ p a i r ( t a s k T a b l e N a m e ,   p r o f i l e T y p e ) ] ) ) ; 
                                 } 
                         } 
                 } 
         } 
         i f   ( ! f o u n d P r o f i l e T y p e S p e c i f i c a t i o n )   { 
                 a v a i l a b l e P r o f i l e T a s k T a b l e P t r s   =   d e f a u l t P r o f i l e T a s k T a b l e P t r s ; 
         } 
 
         f o r ( s i z e _ t   i   =   0 ;   i   <   a v a i l a b l e P r o f i l e T a s k T a b l e P t r s . s i z e ( ) ;   i + + )   { 
                 c o n s t   p a i r < A g e n t P r o f i l e T y p e ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   > &   p r o f i l e T a s k T a b l e P t r   = 
                                       a v a i l a b l e P r o f i l e T a s k T a b l e P t r s [ i ] ; 
 
                 c o n s t   A g e n t P r o f i l e T y p e &   p r o f i l e T y p e   =   p r o f i l e T a s k T a b l e P t r . f i r s t ; 
                 c o n s t   A g e n t P r o f i l e &   p r o f i l e   =   * ( p r o f i l e P t r s [ p r o f i l e T y p e ] ) ; 
 
                 A g e n t T a s k T a b l e &   t a s k T a b l e   =   * ( p r o f i l e T a s k T a b l e P t r . s e c o n d ) ; 
 
                 s h a r e d _ p t r < A g e n t T a s k >   t a s k P t r ( n e w   A g e n t T a s k ( t h i s ) ) ; 
                 A g e n t T a s k &   t a s k   =   * t a s k P t r ; 
 
                 f o r ( s i z e _ t   j   =   0 ;   j   <   c o n d i t i o n S t r i n g s . s i z e ( ) ;   j + + )   { 
                         c o n s t   s t r i n g &   c o n d i t i o n S t r i n g   =   c o n d i t i o n S t r i n g s [ j ] ; 
 
                         i f   ( j   = =   0   & &   c o n d i t i o n S t r i n g . f i n d _ f i r s t _ o f ( " = < > ! " )   = =   s t r i n g : : n p o s )   { 
 
                                 t a s k . s t a r t T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   c o n d i t i o n S t r i n g ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   { 
                                 c o n s t   s i z e _ t   c o n d i t i o n P o s   =   c o n d i t i o n S t r i n g . f i n d _ f i r s t _ o f ( " = < > ! " ) ; 
 
                                 i f   ( ! ( c o n d i t i o n P o s   >   0   & &   c o n d i t i o n P o s   ! =   s t r i n g : : n p o s )   ) { 
                                         c e r r   < <   " E r r o r   c a n ' t   r e a d   c o n d i t i o n   l i n e   "   < <   t a s k L i n e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 c o n s t   s t r i n g   p a r a m e t e r N a m e   =   T r i m m e d S t r i n g ( c o n d i t i o n S t r i n g . s u b s t r ( 0 ,   c o n d i t i o n P o s   -   1 ) ) ; 
 
                                 i f   ( p a r a m e t e r N a m e   = =   " p r o f i l e t y p e " )   { 
                                         c o n t i n u e ; 
                                 } 
 
                                 c o n s t   s t r i n g   v a l u e   =   c o n d i t i o n S t r i n g . s u b s t r ( c o n d i t i o n P o s ) ; 
 
                                 i f   ( ! p r o f i l e . p a r a m e t e r s . C o n t a i n s ( p a r a m e t e r N a m e ) )   { 
                                         c e r r   < <   " E r r o r :   P r o f i l e   T y p e   "   < <   p r o f i l e P t r s . G e t L a b e l ( p r o f i l e T y p e ) 
                                                   < <   "   d o e s n ' t   h a v e   s t a t u s   p a r a m e t e r   "   < <   p a r a m e t e r N a m e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 c o n s t   A g e n t S t a t u s I d T y p e   s t a t u s I d   = 
                                         p r o f i l e . p a r a m e t e r s . G e t I d ( p a r a m e t e r N a m e ) ; 
 
                                 c o n s t   A g e n t C o n d i t i o n C h e c k e r : : C o n d i t i o n P a r a m e t e r T y p e   p a r a m e t e r T y p e   = 
                                         A g e n t C o n d i t i o n C h e c k e r : : C o n v e r t T o P a r a m e t e r T y p e ( s t a t u s I d ) ; 
 
                                 t a s k . c o n d i t i o n C h e c k e r s . p u s h _ b a c k ( 
                                         A g e n t C o n d i t i o n C h e c k e r ( 
                                                 p r o f i l e . p a r a m e t e r s , 
                                                 p a r a m e t e r T y p e , 
                                                 s t a r t T i m e S e c , 
                                                 v a l u e , 
                                                 c h a r a c t o r I d s ) ) ; 
                         } 
                 } 
 
                 v e c t o r < p a i r < s t r i n g ,   s t r i n g >   >   p a r a m e t e r A n d V a l u e s ; 
 
                 b o o l   i s J u s t S t a t u s C h a n g e   =   t r u e ; 
                 b o o l   h a s W a i t i n g A c t i o n   =   f a l s e ; 
                 b o o l   i s I n t e r r p u t i o n B e h a v i o r   =   f a l s e ; 
 
                 f o r ( s i z e _ t   j   =   0 ;   j   <   a c t i o n S t r i n g s . s i z e ( ) ;   j + + )   { 
                         c o n s t   s t r i n g &   a c t i o n S t r i n g   =   a c t i o n S t r i n g s [ j ] ; 
 
                         p a r a m e t e r A n d V a l u e s . p u s h _ b a c k ( S e p a r a t e S t r i n g ( a c t i o n S t r i n g ,     " = " ) ) ; 
 
                         c o n s t   s t r i n g &   p a r a m e t e r N a m e   =   p a r a m e t e r A n d V a l u e s . b a c k ( ) . f i r s t ; 
 
                         i f   ( p a r a m e t e r N a m e   = =   " i n i t i a l l o c a t i o n i d "   | | 
                                 p a r a m e t e r N a m e   = =   " i n i t i a l l o c a t i o n "   | | 
                                 p a r a m e t e r N a m e   = =   " m o v e t o d e s t i n a t i o n i d "   | | 
                                 p a r a m e t e r N a m e   = =   " m o v e t o d e s t i n a t i o n "   | | 
                                 p a r a m e t e r N a m e   = =   " w a i t u n t i l "   | | 
                                 p a r a m e t e r N a m e   = =   " w a i t " )   { 
 
                                 i s J u s t S t a t u s C h a n g e   =   f a l s e ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " i n t e r r u p t c u r r e n t a c t i o n " )   { 
 
                                 c o n s t   s t r i n g &   v a l u e   =   p a r a m e t e r A n d V a l u e s . b a c k ( ) . s e c o n d ; 
 
                                 i f   ( v a l u e   = =   " t e r m i n a t e n o w "   | |   v a l u e   = =   " r e s u m e a f t e r i n t e r r u p t i o n " )   { 
                                         i s I n t e r r p u t i o n B e h a v i o r   =   t r u e ; 
                                 } 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " w a i t " )   { 
                                 h a s W a i t i n g A c t i o n   =   t r u e ; 
                         } 
                 } 
 
                 b o o l   i s B e f o r e S p e c i f i c a t i o n   =   t r u e ; 
                 b o o l   i s B e f o r e W a i t i n g   =   t r u e ; 
 
                 b o o l   s p e c i f i e d D e s t i n a t i o n C h o i c e T y p e   =   f a l s e ; 
 
                 f o r ( s i z e _ t   j   =   0 ;   j   <   p a r a m e t e r A n d V a l u e s . s i z e ( ) ;   j + + )   { 
                         c o n s t   p a i r < s t r i n g ,   s t r i n g > &   p a r a m e t e r A n d V a l u e   =   p a r a m e t e r A n d V a l u e s [ j ] ; 
                         c o n s t   s t r i n g &   p a r a m e t e r N a m e   =   p a r a m e t e r A n d V a l u e . f i r s t ; 
                         c o n s t   s t r i n g &   v a l u e   =   p a r a m e t e r A n d V a l u e . s e c o n d ; 
 
                         i f   ( p a r a m e t e r N a m e   = =   " i n i t i a l l o c a t i o n i d "   | | 
                                 p a r a m e t e r N a m e   = =   " i n i t i a l l o c a t i o n " )   { 
 
                                 i f   ( ! t a s k T a b l e . i n i t i a l L o c a t i o n . l o c a t i o n N a m e . e m p t y ( ) )   { 
                                         c e r r   < <   " E r r o r :   d u p l i c a t e d   l o c a t i o n   d e f i n i t i o n   f o r   "   < <   t a s k L i n e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
                                 i f   ( v a l u e   = =   " i n i t i a l l o c a t i o n " )   { 
                                         c e r r   < <   " E r r o r :   \ " I n i t i a l L o c a t i o n \ "   i s   a   r e s e r v e d   d e s t i n a t i o n   s t r i n g . "   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 i f   ( p a r a m e t e r N a m e   = =   " i n i t i a l l o c a t i o n i d " )   { 
                                         t a s k T a b l e . i n i t i a l L o c a t i o n . i s I d   =   t r u e ; 
                                 } 
                                 t a s k T a b l e . i n i t i a l L o c a t i o n . l o c a t i o n N a m e   =   v a l u e ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " n e a r d e s t i n a t i o n i d "   | | 
                                               p a r a m e t e r N a m e   = =   " n e a r d e s t i n a t i o n " )   { 
 
                                 c e r r   < <   " E r r o r :   U s e   \ " D e s t i n a t i o n = "   < <   v a l u e   < <   " 0D e s t i n a t i o n C h o i c e T y p e = N e a r e s t \ "   s p e c i f i c a t i o n   i n s t e a d   o f   \ " "   < <   p a r a m e t e r N a m e   < <   " = "   < <   v a l u e   < <   " \ " "   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " m o v e t o d e s t i n a t i o n i d "   | | 
                                               p a r a m e t e r N a m e   = =   " m o v e t o d e s t i n a t i o n " )   { 
 
                                 i f   ( ! t a s k . d e s t i n a t i o n . l o c a t i o n N a m e . e m p t y ( ) )   { 
                                         c e r r   < <   " E r r o r :   d u p l i c a t e d   d e s t i n a t i o n   d e f i n i t i o n   f o r   "   < <   t a s k L i n e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 t a s k . d e s t i n a t i o n . l o c a t i o n N a m e   =   v a l u e ; 
 
                                 i s B e f o r e S p e c i f i c a t i o n   =   f a l s e ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " d e s t i n a t i o n c h o i c e t y p e " )   { 
 
                                 i f   ( v a l u e   = =   " n e a r e s t " )   { 
                                         t a s k . d e s t i n a t i o n . l o c a t i o n C h o i c e T y p e   =   A G E N T _ L O C A T I O N _ C H O I C E _ N E A R E S T ; 
                                 }   e l s e   i f   ( v a l u e   = =   " r a n d o m " )   { 
                                         t a s k . d e s t i n a t i o n . l o c a t i o n C h o i c e T y p e   =   A G E N T _ L O C A T I O N _ C H O I C E _ R A N D O M ; 
                                 }   e l s e   { 
                                         c e r r   < <   " E r r o r :   i n v a l i d   d e s t i n a t i o n   c h o i c e   t y p e   "   < <   v a l u e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
                                 s p e c i f i e d D e s t i n a t i o n C h o i c e T y p e   =   t r u e ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " d e s t i n a t i o n c h o i c e b a s e l o c a t i o n " )   { 
 
                                 i f   ( ! t a s k . d e s t i n a t i o n . n e a r e s t C h o i c e B a s e L o c a t i o n N a m e . e m p t y ( ) )   { 
                                         c e r r   < <   " E r r o r :   d u p l i c a t e d   e s t i n a t i o n   c h o i c e   b a s e   l o c a t i o n   d e f i n i t i o n   f o r   "   < <   t a s k L i n e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 t a s k . d e s t i n a t i o n . n e a r e s t C h o i c e B a s e L o c a t i o n N a m e   =   v a l u e ; 
 
                       / /   }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " d e s i g n a t e d d e s t i n a t i o n c h o i c e " )   { 
 
                     / /             i f   ( ! t a s k . d e s t i n a t i o n . d e s t i n e d d e s t i n a t i o n . e m p t y ( ) )   { 
                     / /                     c e r r   < <   " E r r o r :   d u p l i c a t e d   e s t i n a t i o n   c h o i c e   b a s e   l o c a t i o n   d e f i n i t i o n   f o r   "   < <   t a s k L i n e   < <   e n d l ; 
                     / /                     e x i t ( 1 ) ; 
                     / /             } 
 
                     / /             t a s k . d e s t i n a t i o n . d e s t i n e d d e s t i n a t i o n   =   v a l u e ; 
 
                         }     e l s e   i f   ( p a r a m e t e r N a m e   = =   " d e p a r t u r e t i m e " )   { 
 
                                 t a s k . d e p a r t u r e T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " e a r l i e s t d e p a r t u r e t i m e " )   { 
 
                                 t a s k . e a r l y D e p a r t u r e T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " l a t e s t d e p a r t u r e t i m e " )   { 
 
                                 t a s k . l a t e D e p a r t u r e T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " a r r i v a l t i m e " )   { 
 
                                 t a s k . a r r i v a l T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " e a r l i e s t a r r i v a l t i m e " )   { 
 
                                 t a s k . e a r l y A r r i v a l T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " l a t e s t a r r i v a l t i m e " )   { 
 
                                 t a s k . l a t e A r r i v a l T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " w a i t u n t i l " )   { 
 
                                 t a s k . e n d T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                                 i s B e f o r e S p e c i f i c a t i o n   =   f a l s e ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " w a i t " )   { 
 
                                 t a s k . w a i t T i m e   =   A g e n t V a l u e F o r m u l a ( 
                                         p r o f i l e . p a r a m e t e r s ,   0 ,   v a l u e ,   c h a r a c t o r I d s ) ; 
 
                                 i s B e f o r e W a i t i n g   =   f a l s e ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " p r e f e r e d m o b i l i t y m e a n s " )   { 
 
                                 i f   ( v a l u e   = =   " p e d e s t r i a n "   | |   v a l u e   = =   " w a l k " )   { 
                                         t a s k . p r e f e r e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ P E D E S T R I A N ; 
                                 }   e l s e   i f   ( v a l u e   = =   " b i c y c l e " )   { 
                                         t a s k . p r e f e r e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ B I C Y C L E ; 
                                 }   e l s e   i f   ( v a l u e   = =   " v e h i c l e "   | |   v a l u e   = =   " c a r "   | |   v a l u e   = =   " p r i v a t e c a r " )   { 
                                         t a s k . p r e f e r e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ V E H I C L E ; 
                                 }   e l s e   i f   ( v a l u e   = =   " t a x i " )   { 
                                         t a s k . p r e f e r e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ T A X I ; 
                                 }   e l s e   i f   ( v a l u e   = =   " b u s " )   { 
                                         t a s k . p r e f e r e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ B U S ; 
                                 }   e l s e   i f   ( v a l u e   = =   " t r a i n " )   { 
                                         t a s k . p r e f e r e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ T R A I N ; 
                                 }   e l s e   { 
                                         c e r r   < <   " E r r o r :   i n v a l i d   P r e f e r e d M o b i l i t y < e a n s   "   < <   v a l u e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " m o b i l i t y m e a n s " )   { 
 
                                 i f   ( v a l u e   = =   " p e d e s t r i a n "   | |   v a l u e   = =   " w a l k " )   { 
                                         t a s k . b e h a v i o r   =   A G E N T _ B E H A V I O R _ P E D E S T R I A N ; 
                                 }   e l s e   i f   ( v a l u e   = =   " b i c y c l e " )   { 
                                         t a s k . b e h a v i o r   =   A G E N T _ B E H A V I O R _ B I C Y C L E ; 
                                 }   e l s e   i f   ( v a l u e   = =   " v e h i c l e "   | |   v a l u e   = =   " c a r "   | |   v a l u e   = =   " p r i v a t e c a r " )   { 
                                         t a s k . b e h a v i o r   =   A G E N T _ B E H A V I O R _ V E H I C L E ; 
                                 }   e l s e   i f   ( v a l u e   = =   " t a x i " )   { 
                                         t a s k . b e h a v i o r   =   A G E N T _ B E H A V I O R _ T A X I ; 
                                 }   e l s e   i f   ( v a l u e   = =   " b u s " )   { 
                                         t a s k . b e h a v i o r   =   A G E N T _ B E H A V I O R _ B U S ; 
                                 }   e l s e   i f   ( v a l u e   = =   " t r a i n " )   { 
                                         t a s k . b e h a v i o r   =   A G E N T _ B E H A V I O R _ T R A I N ; 
                                 }   e l s e   { 
                                         c e r r   < <   " E r r o r :   i n v a l i d   M o b i l i t y < e a n s   "   < <   v a l u e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " r e s e r v a t i o n " )   { 
 
                                 i f   ( ! I s F u n c t i o n S t r i n g ( v a l u e ) )   { 
                                         c e r r   < <   " E r r o r :   i n v a l i d   r e s e r v a t i o n     "   < <   v a l u e   < <   e n d l ; 
                                         e x i t ( 1 ) ; 
                                 } 
 
                                 c o n s t   s i z e _ t   a r c P o s   =   v a l u e . f i n d _ f i r s t _ o f ( ' ( ' ) ; 
                                 c o n s t   s t r i n g   f u n c t i o n S t r i n g   =   v a l u e . s u b s t r ( 0 ,   a r c P o s ) ; 
 
                                 c e r r   < <   " E r r o r :   i n v a l i d   r e s e r v a t i o n   f u n c t i o n   "   < <   f u n c t i o n S t r i n g   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " i n t e r s e c t i o n s t o g o t h r o u g h " )   { 
 
                                 d e q u e < s t r i n g >   p a s s I n t e r s e c t i o n N a m e s ; 
                                 T o k e n i z e T o T r i m m e d L o w e r S t r i n g ( v a l u e ,   " : " ,   p a s s I n t e r s e c t i o n N a m e s ) ; 
 
                                 f o r ( s i z e _ t   k   =   0 ;   k   <   p a s s I n t e r s e c t i o n N a m e s . s i z e ( ) ;   k + + )   { 
                                         t a s k . p a s s I n t e r s e c t i o n L o c a t i o n I n f o s . p u s h _ b a c k ( 
                                                 L o c a t i o n I n f o ( 
                                                         f a l s e / * i s I d * / , 
                                                         A G E N T _ L O C A T I O N _ C H O I C E _ R A N D O M , 
                                                         p a s s I n t e r s e c t i o n N a m e s [ k ] ) ) ; 
                                 } 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " i n t e r r u p t c u r r e n t a c t i o n " )   { 
 
                                 i f   ( v a l u e   = =   " t e r m i n a t e n o w " )   { 
                                         t a s k . i n t e r r u p t i o n T y p e   =   A G E N T _ B E H A V I O R _ I N T E R R U P T I O N _ R E P L A C E ; 
                                 }   e l s e   i f   ( v a l u e   = =   " r e s u m e a f t e r i n t e r r u p t i o n " )   { 
                                         t a s k . i n t e r r u p t i o n T y p e   =   A G E N T _ B E H A V I O R _ I N T E R R U P T I O N _ L A T E R ; 
                                 }   e l s e   { 
                                         t a s k . i n t e r r u p t i o n T y p e   =   A G E N T _ B E H A V I O R _ I N T E R R U P T I O N _ N O N E ; 
                                 } 
 
                         }   e l s e   i f   ( p a r a m e t e r N a m e   = =   " g e n e r a t e a p p l i c a t i o n " )   { 
 
                                 s t r i n g   a p p l i c a t i o n M o d e l N a m e ; 
                                 s t r i n g   i n s t a n c e N a m e ; 
                                 v e c t o r < D y n a m i c A p p l i c a t i o n D e f i n i t i o n P a r a m e t e r >   a p p l i c a t i o n P a r a m e t e r s ; 
 
                                 R e s o l v e A p p l i c a t i o n P a r a m e t e r S p e c i f i c a t i o n ( 
                                         v a l u e , 
                                         i n s t a n c e N a m e , 
                                         a p p l i c a t i o n M o d e l N a m e , 
                                         a p p l i c a t i o n P a r a m e t e r s ) ; 
 
                                 c o n s t   A g e n t S t a t u s C h a n g e T y p e   c h a n g e T y p e   =   G e t S t a t u s C h a n g e T y p e ( 
                                         i s J u s t S t a t u s C h a n g e , 
                                         h a s W a i t i n g A c t i o n , 
                                         i s B e f o r e S p e c i f i c a t i o n , 
                                         i s I n t e r r p u t i o n B e h a v i o r , 
                                         i s B e f o r e W a i t i n g ) ; 
 
                                 c o n s t   D y n a m i c A p p l i c a t i o n I d T y p e   d y n a m i c A p p l i c a t i o n I d ( 
                                         a p p l i c a t i o n M o d e l N a m e , 
                                         i n s t a n c e N a m e ) ; 
 
                                 t a s k . a d d i t i o n a l S t a t u s C h a n g e s [ c h a n g e T y p e ] . a p p l i c a t i o n S p e c i f i c a t i o n s [ d y n a m i c A p p l i c a t i o n I d ] . p a r a m e t e r s   =   a p p l i c a t i o n P a r a m e t e r s ; 
 
                         }   e l s e   { 
                                 / / a s s e r t ( p r o f i l e . p a r a m e t e r s . C o n t a i n s ( p a r a m e t e r N a m e ) ) ; 
 
                                 i f   ( ! p r o f i l e . p a r a m e t e r s . C o n t a i n s ( p a r a m e t e r N a m e ) )   { 
                                         c e r r   < <   " W a r n i n g :   C o u l d n ' t   f i n d   a n   a g e n t   p r o f i l e   p a r a m e t e r :   "   < <   p a r a m e t e r N a m e   < <   e n d l 
                                                   < <   "       A   p r o f i l e   c h a n g e   b e h a v i o r   [ "   < <   a c t i o n S t r i n g s [ j ]   < <   " ]   i s   s k i p p p e d . "   < <   e n d l ; 
                                         c o n t i n u e ; 
                                 } 
 
                                 c o n s t   A g e n t S t a t u s C h a n g e T y p e   c h a n g e T y p e   =   G e t S t a t u s C h a n g e T y p e ( 
                                         i s J u s t S t a t u s C h a n g e , 
                                         h a s W a i t i n g A c t i o n , 
                                         i s B e f o r e S p e c i f i c a t i o n , 
                                         i s I n t e r r p u t i o n B e h a v i o r , 
                                         i s B e f o r e W a i t i n g ) ; 
 
                                 c o n s t   A g e n t S t a t u s I d T y p e   s t a t u s I d   = 
                                         p r o f i l e . p a r a m e t e r s . G e t I d ( p a r a m e t e r N a m e ) ; 
 
                                 t a s k . a d d i t i o n a l S t a t u s C h a n g e s [ c h a n g e T y p e ] . s t a t u s C h a n g e s . p u s h _ b a c k ( 
                                         m a k e _ p a i r ( s t a t u s I d ,   A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   v a l u e ,   c h a r a c t o r I d s ) ) ) ; 
                         } 
                 } 
 
                 i f   ( i s I n t e r r p u t i o n B e h a v i o r )   { 
                         i f   ( i s J u s t S t a t u s C h a n g e )   { 
                                 c e r r   < <   " E r r o r :   S p e c i f y   d e s t i n a t i o n   o r   w a i t   f o r   I n t e r r u p t C u r r e n t A c t i o n   "   < <   a c t i o n L i n e   < <   e n d l ; 
                                 e x i t ( 1 ) ; 
                         } 
                         t a s k T a b l e . i n t e r r u p t T a s k P t r s . p u s h _ b a c k ( t a s k P t r ) ; 
 
                 }   e l s e   { 
 
                         i f   ( i s J u s t S t a t u s C h a n g e )   { 
                                 t a s k T a b l e . s t a t u s C h a n g e P t r s . p u s h _ b a c k ( t a s k P t r ) ; 
                         }   e l s e   { 
                                 t a s k T a b l e . t a s k P t r s . p u s h _ b a c k ( t a s k P t r ) ; 
                         } 
                 } 
 
                 i f   ( t a s k T a b l e . i n i t i a l L o c a t i o n . l o c a t i o n N a m e . e m p t y ( ) )   { 
                         c e r r   < <   " E r r o r :   S e t   i n i t i a l   l o c a t i o n   f o r   B e h a v i o r   T y p e   "   < <   t a s k T a b l e N a m e   < <   "   P r o f i l e   T y p e   "   < <   p r o f i l e P t r s . G e t L a b e l ( p r o f i l e T y p e )   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
         } 
 } 
 
 A g e n t V a l u e F o r m u l a   A g e n t P r o f i l e A n d T a s k T a b l e : : M a k e V a l u e F o r m u l a ( 
         c o n s t   A g e n t P r o f i l e T y p e &   p r o f i l e T y p e , 
         c o n s t   s t r i n g &   f o r m u l a ) 
 { 
         c o n s t   A g e n t P r o f i l e &   p r o f i l e   =   * p r o f i l e P t r s [ p r o f i l e T y p e ] ; 
 
         c o n s t   d o u b l e   d e f a u l t V a l u e   =   0 ; 
         c o n s t   d o u b l e   s t a r t T i m e S e c   =   0 ; 
 
         r e t u r n   A g e n t V a l u e F o r m u l a ( p r o f i l e . p a r a m e t e r s ,   s t a r t T i m e S e c ,   f o r m u l a ,   c h a r a c t o r I d s ,   d e f a u l t V a l u e ) ; 
 } 
 
 
 } / / n a m e s p a c e 
 